#include <string.h>
#include <sys/wait.h>
#include "ft_shell.h"
#include "ft_utils.h"

static void	ft_tblclear(char ***tbl)
{
	char	**cp;

	if (*tbl)
	{
		cp = *tbl;
		while (*cp)
			free(*cp++);
		free(*tbl);
		*tbl = NULL;
	}
}

static char	**ft_commandline_make(t_queue *strs, size_t size)
{
	char	**argv;
	size_t	i;

	argv = malloc(sizeof(char *) * (size + 1));
	if (!argv)
		return (NULL);
	i = 0U;
	while (i < size)
	{
		argv[i] = ft_strdup((char *)ft_queue_front(strs));
		if (!argv[i])
		{
			ft_tblclear(&argv);
			return (NULL);
		}
		ft_queue_pop(strs);
		++i;
	}
	argv[size] = NULL;
	return (argv);
}

static int	ft_shell_builtin_cd(size_t size, char *argv[])
{
	if (size != 2U)
	{
		ft_putendl_fd("error: cd: bad arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	//ft_putendl_fd(getcwd(NULL, 0), STDOUT_FILENO);
	if (chdir(argv[1]) < 0)
	{
		ft_putstr_fd("error: cd: cannot change directory to ", STDERR_FILENO);
		ft_putendl_fd(argv[1], STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	//ft_putendl_fd(getcwd(NULL, 0), STDOUT_FILENO);
	return (EXIT_SUCCESS);
}

// ------------------

static void	ft_dup2(int oldfd, int newfd)
{
	int		fd;

	if (oldfd != newfd)
	{
		fd = dup2(oldfd, newfd);
		close(oldfd);
		if (fd < 0)
		{
			ft_putendl_fd("error: fatal", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
}

static void	ft_execve(char *argv[], char *envp[])
{
	if (execve(argv[0], argv, envp) < 0)
	{
		ft_putstr_fd("error: cannot execute ", STDERR_FILENO);
		ft_putendl_fd(argv[0], STDERR_FILENO);
		exit(127);
	}
}

// ------------------

static pid_t	ft_process_create(int pipefd[])
{
	pid_t	pid;

	if (pipefd)
	{
		if (pipe(pipefd) < 0)
			return (-1);
	}
	pid = fork();
	if (pid < 0)
	{
		if (pipefd)
		{
			close(pipefd[0]);
			close(pipefd[1]);
		}
		return (-1);
	}
	return (pid);
}

static void	ft_process_redir(int fdin, int fdout)
{
	ft_dup2(fdin, STDIN_FILENO);
	ft_dup2(fdout, STDOUT_FILENO);
}

static void	ft_process_exec(t_queue *strs, char *envp[])
{
	size_t	size;
	char	**argv;
	int		exitstatus;

	if (strs && !ft_queue_empty(strs))
	{
		size = ft_queue_size(strs);
		argv = ft_commandline_make(strs, size);
		if (!argv)
		{
			ft_putendl_fd("error: fatal", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		if (!strcmp(argv[0], "cd"))
		{
			exitstatus = ft_shell_builtin_cd(size, argv);
			ft_tblclear(&argv);
			exit(exitstatus);
		}
		else
			ft_execve(argv, envp);
	}
	else
		exit(EXIT_SUCCESS);
}

// ------------------

static void	ft_shell_loop_process(t_expr *expr, int prev_pipe, int pipefd[], char *envp[])
{
	close(pipefd[0]);
	ft_process_redir(prev_pipe, (expr->type == TYPE_SEMICOLON) ? STDOUT_FILENO : pipefd[1]);
	ft_process_exec(expr->strs, envp);
}

static int	ft_shell_last_process(t_expr *expr, int prev_pipe, t_shell *s)
{
	pid_t	pid;
	int		stat;

	pid = ft_process_create(NULL);
	if (pid < 0)
		ft_shell_error(s, "error: fatal");
	if (pid == 0)
	{
		ft_process_redir(prev_pipe, STDOUT_FILENO);
		ft_process_exec(expr->strs, s->environ);
	}
	if (prev_pipe != STDIN_FILENO)
		close(prev_pipe);
	if (waitpid(pid, &stat, 0) < 0)
		ft_shell_error(s, "error: fatal");
	return (WEXITSTATUS(stat));
}

static int	ft_shell_pipeline(t_shell *s)
{
	pid_t	pid;
	int		pipefd[2];
	int		prev_pipe;
	t_expr	*expr;

	prev_pipe = STDIN_FILENO;
	while (ft_queue_size(s->exprs) > 1U)
	{
		expr = (t_expr *)ft_queue_front(s->exprs);
		pid = ft_process_create(pipefd);
		if (pid < 0)
			ft_shell_error(s, "error: fatal");
		if (pid == 0)
			ft_shell_loop_process(expr, prev_pipe, pipefd, s->environ);
		close(pipefd[1]);
		if (prev_pipe != STDIN_FILENO)
			close(prev_pipe);
		prev_pipe = pipefd[0];
		if (expr->type == TYPE_SEMICOLON)
		{
			close(prev_pipe);
			prev_pipe = STDIN_FILENO;
		}
		if (waitpid(pid, NULL, 0) < 0)
			ft_shell_error(s, "error: fatal");
		ft_expr_delone(expr);
		ft_queue_pop(s->exprs);
	}
	expr = (t_expr *)ft_queue_front(s->exprs);
	return (ft_shell_last_process(expr, prev_pipe, s));
}

static int	ft_shell_builtins_single_expr(t_expr *expr, t_shell *s)
{
	size_t	size;
	char	**argv;
	int		exitstatus;

	size = ft_queue_size(expr->strs);
	argv = ft_commandline_make(expr->strs, size);
	if (!argv)
		ft_shell_error(s, "error: fatal");
	if (!strcmp(argv[0], "cd"))
		exitstatus = ft_shell_builtin_cd(size, argv);
	else
		exitstatus = EXIT_FAILURE;
	ft_tblclear(&argv);
	return (exitstatus);
}

// ------------------

void	ft_shell_routine(t_shell *s)
{
	t_expr	*expr;

	expr = (t_expr *)ft_queue_front(s->exprs);
	if (ft_queue_size(s->exprs) == 1U \
			&& expr->strs && !ft_queue_empty(expr->strs) \
			&& !strcmp((char *)ft_queue_front(expr->strs), "cd"))
		s->exitstatus = ft_shell_builtins_single_expr(expr, s);
	else
		s->exitstatus = ft_shell_pipeline(s);
}

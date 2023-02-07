#include "ft_shell.h"
#include "ft_utils.h"

void	ft_shell_init(t_shell *s)
{
	s->exprs = malloc(sizeof(t_queue));
	if (!(s->exprs))
		ft_shell_error(s, "error: fatal");
	ft_queue_create(s->exprs);
	s->environ = NULL;
	s->exitstatus = EXIT_SUCCESS;
}

void	ft_shell_destroy(t_shell *s)
{
	if (s->exprs)
	{
		ft_exprs_cleanup(s->exprs);
		ft_queue_destroy(s->exprs);
		free(s->exprs);
		s->exprs = NULL;
	}
	s->environ = NULL;
}

void	ft_shell_error(t_shell *s, const char *errormsg)
{
	if (errormsg)
		ft_putendl_fd(errormsg, STDERR_FILENO);
	ft_shell_destroy(s);
	exit(EXIT_FAILURE);
}

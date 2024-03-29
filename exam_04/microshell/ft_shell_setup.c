#include <string.h>
#include "ft_shell.h"
#include "ft_utils.h"

static t_expr	*ft_expr_create(void)
{
	t_expr	*expr;

	expr = malloc(sizeof(t_expr));
	if (!expr)
		return (NULL);
	expr->strs = malloc(sizeof(t_queue));
	if (!(expr->strs))
	{
		free(expr);
		return (NULL);
	}
	ft_queue_create(expr->strs);
	expr->type = TYPE_NONE;
	return (expr);
}

void	ft_shell_setup(t_shell *s, int argc, char *argv[], char *envp[])
{
	int		i;
	t_expr	*expr;

	i = 0;
	expr = NULL;
	while (++i < argc)
	{
		if (!expr)
			expr = ft_expr_create();
		if (!expr)
			ft_shell_error(s, "error: fatal");

		if (!strcmp(argv[i], "|"))
			expr->type = TYPE_PIPE;
		else if (!strcmp(argv[i], ";"))
			expr->type = TYPE_SEMICOLON;

		if (expr->type != TYPE_NONE)
		{
			ft_queue_push(s->exprs, expr, sizeof(t_expr));
			free(expr);
			expr = NULL;
		}
		else
			ft_queue_push(expr->strs, argv[i], ft_strlen(argv[i]) + 1);
	}
	if (expr)
	{
		ft_queue_push(s->exprs, expr, sizeof(t_expr));
		free(expr);
	}
	s->environ = envp;
}

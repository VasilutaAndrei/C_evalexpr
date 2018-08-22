/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasilut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 11:54:36 by avasilut          #+#    #+#             */
/*   Updated: 2017/08/27 00:34:46 by avasilut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evexp.h"
#define OPERATOR(x)	(x == '+' || x == '-' || x == '*' || x == '/' || x == '%')
#define OP_1(x)		(x == '*' || x == '/' || x == '%')
#define OP_2(x)		(x == '+' || x == '-')
#define IS_DIGIT(x)	(x >= '0' && x <= '9')

int		parcurge(char **expr)
{
	int n1;

	if (**expr == '(')
	{
		(*expr)++;
		n1 = operatie_grad_2(expr);
		if (**expr == ')')
			(*expr)++;
		return (n1);
	}
	return (ft_atoi(expr));
}

int		operatie_grad_1(char **expr)
{
	int		n1;
	int		n2;
	char	op;

	n1 = parcurge(expr);
	while (**expr)
	{
		op = **expr;
		if (!OP_1(op))
			return (n1);
		(*expr)++;
		n2 = parcurge(expr);
		n1 = operatie(n1, op, n2);
	}
	return (n1);
}

int		operatie_grad_2(char **expr)
{
	int		n1;
	int		n2;
	char	op;

	n1 = operatie_grad_1(expr);
	while (**expr)
	{
		op = **expr;
		if (!OP_2(op))
			return (n1);
		(*expr)++;
		n2 = operatie_grad_1(expr);
		n1 = operatie(n1, op, n2);
	}
	return (n1);
}

int		rem_double_ops(char *expr, int l)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i <= l)
	{
		if (expr[i] == '-' && expr[i + 1] == '-')
		{
			expr[k++] = '+';
			i++;
		}
		else if ((expr[i] == '+' && expr[i + 1] == '-') ||
			(expr[i] == '-' && expr[i + 1] == '+'))
		{
			expr[k++] = '-';
			i++;
		}
		else
			expr[k++] = expr[i];
		i++;
	}
	expr[k] = '\0';
	return (operatie_grad_2(&expr));
}

int		eval_expr(char *expr)
{
	int		i;
	int		k;
	int		l;

	i = 0;
	k = 0;
	l = ft_strlen(expr);
	while (i <= l)
	{
		if (expr[i] != ' ')
			expr[k++] = expr[i];
		i++;
	}
	return (rem_double_ops(expr, l));
}

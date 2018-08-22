/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasilut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 11:59:06 by avasilut          #+#    #+#             */
/*   Updated: 2017/08/26 11:59:08 by avasilut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int a)
{
	if (a == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	else if (a < 0)
	{
		ft_putchar('-');
		a = -a;
	}
	if (a >= 10)
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
	else
		ft_putchar(a + '0');
}

int		ft_strlen(char *exp)
{
	int i;

	i = 0;
	while (exp[i] != '\0')
		i++;
	return (i);
}

int		ft_atoi(char **s)
{
	int		nbr;

	nbr = 0;
	while (**s >= '0' && **s <= '9')
	{
		nbr = nbr * 10 + (**s - '0');
		(*s)++;
	}
	return (nbr);
}

int		operatie(int x, char op, int y)
{
	if (op == '+')
		return (x + y);
	if (op == '-')
		return (x - y);
	if (op == '/')
		return (x / y);
	if (op == '*')
		return (x * y);
	if (op == '%')
		return (x % y);
	return (0);
}

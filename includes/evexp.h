/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evexp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasilut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 11:57:15 by avasilut          #+#    #+#             */
/*   Updated: 2017/08/27 00:34:01 by avasilut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVEXP_H
# define EVEXP_H

void	ft_putchar(char c);
void	ft_putnbr(int a);
int		ft_atoi(char **s);
int		ft_strlen(char *exp);
int		eval_expr(char *expr);
int		parcurge(char **expr);
int		operatie_grad_1(char **expr);
int		operatie_grad_2(char **expr);
int		rem_double_ops(char *expr, int l);
int		operatie(int x, char op, int y);
#endif

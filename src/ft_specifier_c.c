/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:21:02 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/15 19:49:27 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_specifier_c(va_list arg, int *res, t_printf *t_flag)
{
	char c;

	t_flag->conv = 0;
	c = va_arg(arg, int);
	if (t_flag->space_b)
		ft_space(t_flag->space_b - 1, 1, res, t_flag);
	if (t_flag->fl_z_before)
		ft_space(t_flag->fl_z_before - 1, 0, res, t_flag);
	if (c)
		ft_putchar_fd(c, 1);
	else
		write(1, "\0", 1);
	*res += 1;
	if (t_flag->space_a > 0)
		ft_space(t_flag->space_a - 1, 1, res, t_flag);
}

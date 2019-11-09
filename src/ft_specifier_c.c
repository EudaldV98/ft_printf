/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:21:02 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/09 20:05:22 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_specifier_c(va_list arg, int *res, t_printf *t_flag)
{
	char c;

	t_flag->conv = 0;
	t_flag->width = t_flag->fl_z_before;
	c = va_arg(arg, int);
	ft_update_value(t_flag, 0, CHAR);
	ft_handle_spaces(res, t_flag, 1, 0);
	if (c)
		ft_putchar_fd(c, 1);
	else
		write(1, "\0", 1);
	*res += 1;
	if (t_flag->space_a > 0)
		ft_space(t_flag->space_a, 1, res, t_flag);
}

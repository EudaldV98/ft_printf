/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:56:11 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/07 15:24:21 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_s(va_list arg, int *res, t_printf *t_flag)
{
	char *str;

	t_flag->conv = 0;
	t_flag->width = t_flag->fl_z_before;
	str = va_arg(arg, char *);
	ft_update_value(t_flag, 0, CHAR);
	ft_handle_space(res, t_flag, 1, 0);
	if (str)
		ft_out(str, res, t_flag);
	else
		ft_out("(null)", res, t_flag);
	if (t_flag->space_a > 0)
		ft_space(t_flag->space_a, 1, res, t_flag);
}

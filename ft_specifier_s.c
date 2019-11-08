/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:56:11 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/08 15:44:50 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_s(va_list arg, int *res, t_printf *t_flag)
{
	char	*str;
	int		size;

	t_flag->conv = 0;
	str = va_arg(arg, char *);
	size = ft_strlen(str);
	if (!str)
		size = 6;
	if ((t_flag->flag == 3 || t_flag->flag == 2) && !t_flag->fl_z_before)
	{
		if (t_flag->space_b)
			ft_space(t_flag->space_b, 1, res, t_flag);
		return ;
	}
	if (t_flag->fl_star == 2 && t_flag->fl_z_before > t_flag->space_b
		&& t_flag->flag != 3)
	{
		t_flag->space_b = 0;
		t_flag->space_a = 0;
	}
	else if (t_flag->fl_point && t_flag->width < size && t_flag->width != 1)
		ft_space(t_flag->space_b - t_flag->width, 1, res, t_flag);
	else
		ft_space(t_flag->space_b - size, 1, res, t_flag);
	if (str)
		ft_out(str, res, t_flag);
	else
		ft_out("(null)", res, t_flag);
	if (t_flag->space_a && t_flag->fl_point && t_flag->width < size)
		ft_space(t_flag->space_a - t_flag->width, 1, res, t_flag);
	else if (t_flag->space_a)
		ft_space(t_flag->space_a - size, 1, res, t_flag);
}

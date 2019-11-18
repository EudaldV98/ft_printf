/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:12:35 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/18 16:51:02 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_flag_ptr_aux(int nb, char c, t_printf *t_flag)
{
	if (nb > 0)
	{
		t_flag->space_b = nb;
		if (c == 's')
		{
			t_flag->flag = 0;
			if (t_flag->fl_point)
				t_flag->space_b = 0;
		}
	}
	else if (nb <= 0)
	{
		t_flag->space_a = -nb;
		if (c == 's')
		{
			t_flag->flag = 0;
			t_flag->space_a = 0;
		}
	}
	if (t_flag->space_a > 0 && t_flag->fl_z_before > 0 && t_flag->fl_star == 2)
		t_flag->space_a -= t_flag->fl_z_before;
}

void	ft_flag_ptr(va_list arg, int *i, t_printf *t_flag, char *str)
{
	int nb;

	if (!t_flag->fl_star)
	{
		nb = va_arg(arg, int);
		if (t_flag->flag == 3 && nb <= 0)
		{
			t_flag->space_b = 0;
			t_flag->space_a = 0;
			if (nb != 0)
				t_flag->flag = 0;
		}
		else
			ft_flag_ptr_aux(nb, str[0], t_flag);
	}
	else
	{
		nb = va_arg(arg, int);
		t_flag->fl_z_before = nb;
		if (t_flag->flag == 3 && nb <= 0)
		{
			t_flag->fl_z_before = 0;
			if (nb != 0)
				t_flag->flag = 0;
		}
	}
	t_flag->fl_star += 1;
	if (t_flag->space_a > 0 && t_flag->fl_z_before > 0 && t_flag->fl_star == 2)
		t_flag->space_a -= t_flag->fl_z_before;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:12:35 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/15 19:26:06 by jvaquer          ###   ########.fr       */
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
	else if (nb < 0)
	{
		t_flag->space_a = -nb;
		if (c == 's')
		{
			t_flag->flag = 0;
			t_flag->space_a = 0;
		}
	}
}

void	ft_flag_ptr(va_list arg, int *i, t_printf *t_flag, char *str)
{
	int nb;

	if (!t_flag->fl_star)
	{
		nb = va_arg(arg, int);
		if (t_flag->flag == 3 && (str[0] == 'i' || str[0] == 'd'
		|| str[0] == 'u') && nb <= 0)
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
		t_flag->fl_z_before = va_arg(arg, int);
	t_flag->fl_star += 1;
}

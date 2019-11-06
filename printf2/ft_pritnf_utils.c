/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pritnf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:06:21 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/06 18:15:01 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_out(char *str, int *res, t_printf *t_flag)
{
	int i;

	i = 0;
	while (t_flag->width != 0 && str[i])
	{
		ft_putchar_fd(str[i], 1);
		*res += 1;
		t_flag->width--;
		i++;
	}
}

void	ft_update_value(t_printf *t_flag, int neg)
{
	if (t_flag->fl_z_before > t_flag->width && t_flag->width != 1)
		t_flag->space_b = t_flag->fl_z_before - t_flag->width + neg;
	if (t_flag->flag == 1)
	{
		t_flag->space_b += t_flag->fl_z_before;
		t_flag->fl_z_before = 0;
	}
	else if (t_flag->flag == 2)
	{
		if (t_flag->fl_z_before < t_flag->size)
			t_flag->fl_z_before = 0;
		else
			t_flag->fl_z_before -= t_flag->width;
		if (t_flag->space_b < t_flag->size)
			t_flag->space_b = 0;
		else
			t_flag->space_b -= 2;
	}
	else if (t_flag->flag == 3)
	{
		t_flag->space_b -= 1;
		t_flag->fl_z_before = 0;
	}
	else if (t_flag->flag == 4)
	{
		t_flag->space_b = t_flag->fl_z_before;
		if (t_flag->width > -1)
		{
			t_flag->space_b -= t_flag->width - t_flag->size;
			t_flag->fl_z_before -= t_flag->width - t_flag->size;
		}
	}
	if (t_flag->space_b && t_flag->width > -1)
		t_flag->space_b -= t_flag->width + neg;
	if (t_flag->space_b)
		t_flag->space_b -= t_flag->size;
	if (t_flag->fl_z_before && t_flag->width > -1)
		t_flag->fl_z_before -= t_flag->width + t_flag->size;
	if (t_flag->width > -1 && !t_flag->fl_z_before)
		t_flag->fl_z_before += t_flag->width - t_flag->size + neg;
	if (t_flag->width > t_flag->fl_z_before)
		t_flag->fl_z_before = t_flag->width - t_flag->size + neg;
	if (t_flag->width > t_flag->space_b)
		t_flag->space_b = 0;
}

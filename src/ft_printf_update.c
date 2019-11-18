/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:06:21 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/18 16:37:29 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_update_space_b(t_printf *t_flag, int neg)
{
	if (t_flag->width > -1)
	{
		if (t_flag->fl_z_before > t_flag->width)
		{
			if (t_flag->size > t_flag->width)
				t_flag->space_b = t_flag->fl_z_before - t_flag->size;
			else
				t_flag->space_b = t_flag->fl_z_before - t_flag->width - neg;
			t_flag->fl_z_before = 0;
		}
		else if (t_flag->space_b && t_flag->fl_point)
		{
			if (t_flag->size <= t_flag->width)
				t_flag->space_b -= t_flag->width + neg;
			else if (t_flag->size > t_flag->width)
				t_flag->space_b -= t_flag->size;
		}
	}
	else if (t_flag->fl_z_before)
		t_flag->space_b -= (t_flag->fl_z_before);
	else
		t_flag->space_b -= (t_flag->size);
}

void	ft_update_zero_b(t_printf *t_flag, int neg)
{
	if (t_flag->width > -1)
	{
		if (t_flag->fl_z_before)
			t_flag->fl_z_before -= t_flag->width + t_flag->size;
		else
			t_flag->fl_z_before += t_flag->width - t_flag->size + neg;
	}
	else
		t_flag->fl_z_before -= t_flag->size;
	if (t_flag->width > t_flag->fl_z_before)
		t_flag->fl_z_before = t_flag->width - t_flag->size + neg;
}

void	ft_update_space_a(t_printf *t_flag, int neg)
{
	if (t_flag->space_a)
	{
		if (t_flag->width > -1)
		{
			if (t_flag->size > t_flag->width)
				t_flag->space_a -= (t_flag->size);
			else
				t_flag->space_a -= (t_flag->width + neg);
		}
		else
			t_flag->space_a -= t_flag->size;
	}
}

void	ft_handle_exceptions(t_printf *t_flag, int type, int neg)
{
	if (t_flag->flag == 4 && t_flag->fl_z_before && t_flag->space_b < 0)
	{
		t_flag->space_b = t_flag->fl_z_before;
		t_flag->fl_z_before = 0;
	}
	if (t_flag->flag == 3 && !t_flag->fl_star &&
		t_flag->space_b < 0 && t_flag->fl_z_before)
	{
		t_flag->space_b = t_flag->fl_z_before;
		t_flag->fl_z_before = 0;
	}
	if (t_flag->flag == 3 && t_flag->fl_star && t_flag->space_b > 0
	&& neg)
		t_flag->space_b--;
	if (t_flag->flag == 5)
		t_flag->space_b -= t_flag->space_a;
	if (type == PADD)
	{
		if (t_flag->space_b > 0)
			t_flag->space_b -= 2;
		else if (t_flag->fl_z_before > 0)
			t_flag->fl_z_before -= 2;
		else if (t_flag->space_a > 0)
			t_flag->space_a -= 2;
	}
}

void	ft_update_value(t_printf *t_flag, int neg, int type)
{
	if (t_flag->fl_z && !t_flag->fl_z_before && t_flag->fl_star)
	{
		t_flag->fl_z_before = t_flag->space_b;
		t_flag->space_b = 0;
	}
	ft_update_space_b(t_flag, neg);
	ft_update_zero_b(t_flag, neg);
	ft_update_space_a(t_flag, neg);
	ft_handle_exceptions(t_flag, type, neg);
}

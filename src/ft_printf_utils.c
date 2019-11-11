/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:41:49 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/11 18:16:28 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_out(char *str, int *res, t_printf *t_flag)
{
	int i;
	int width;

	i = 0;
	width = t_flag->width;
	while (t_flag->width != 0 && str[i])
	{
		ft_putchar_fd(str[i], 1);
		*res += 1;
		width--;
		i++;
	}
}

void	ft_space(int nb, int cas, int *res, t_printf *t_flag)
{
	while (nb > 0)
	{
		if (cas)
			ft_putchar_fd(' ', 1);
		else
			ft_putchar_fd('0', 1);
		*res += 1;
		nb--;
	}
}

void	ft_handle_spaces(int *res, t_printf *t_flag, int size, int neg)
{
	if (t_flag->space_b)
		ft_space(t_flag->space_b, 1, res, t_flag);
	if (neg)
		write(1, "-", 1);
	else if (t_flag->flag == 7)
		write(1, "0x", 2);
	if (t_flag->fl_z_before)
	{
		ft_space(t_flag->fl_z_before, 0, res, t_flag);
	}
}

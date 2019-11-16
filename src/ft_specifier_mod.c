/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:51:08 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/15 16:27:51 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_specifier_mod(int *res, t_printf *t_flag)
{
	t_flag->conv = 0;
	if (t_flag->fl_min && t_flag->flag == 5)
		t_flag->space_b = 0;
	if (t_flag->space_b)
		ft_space(t_flag->space_b - 1, 1, res, t_flag);
	if (t_flag->fl_z_before)
		ft_space(t_flag->fl_z_before - 1, 0, res, t_flag);
	ft_putchar_fd('%', 1);
	*res += 1;
	if (t_flag->space_a > 0)
		ft_space(t_flag->space_a - 1, 1, res, t_flag);
}

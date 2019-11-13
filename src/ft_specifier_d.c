/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:02:59 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/13 17:14:56 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_nb_exception(long long nb, int *res, t_printf *t_flag)
{
	if (t_flag->flag == 1 && nb == 0)
		return (1);
	if (t_flag->flag == 2 && nb == 0)
	{
		if (t_flag->space_a > 0)
			ft_space(t_flag->space_a + 1, 1, res, t_flag);
		if (t_flag->size == 1 && t_flag->space_b > 0)
			ft_space(t_flag->space_a + 1, 1, res, t_flag);
		return (1);
	}
	if (t_flag->flag == 3 && nb == 0)
	{
		if (t_flag->space_a > 0)
			ft_space(t_flag->space_a, 1, res, t_flag);
		if (t_flag->size == 1 && t_flag->space_b > 0)
			ft_space(t_flag->space_a + 1, 1, res, t_flag);
		return (1);
	}
	return (0);
}

void	ft_specifier_d(va_list aux, int *res, t_printf *t_flag)
{
	long long	nb;

	t_flag->conv = 0;
	nb = (long long)va_arg(aux, int);
	t_flag->size = ft_strlen_nb(nb);
	ft_update_value(t_flag, ((nb < 0) ? 1 : 0), NUMB);
	if (nb <= 0 && t_flag->fl_z_before > 0 && t_flag->fl_star)
		t_flag->fl_z_before++;
	// if (t_flag->fl_z_before <= 0 && t_flag->space_b && t_flag->fl_point >= 1)
	// {
	// 	t_flag->fl_z_before = t_flag->space_b;
	// 	if (nb < 0)
	// 		t_flag->fl_z_before++;
	// 	t_flag->space_b = 0;
	// }
	ft_handle_spaces(res, t_flag, 1, ((nb < 0) ? 1 : 0));
	if (nb == -2147483647)
		nb = nb;
	else if (nb < 0)
		nb = -nb;
	if (ft_nb_exception(nb, res, t_flag))
		return ;
	ft_putlng_fd(nb, 1);
	*res += t_flag->size;
	if (t_flag->space_a > 0)
		ft_space(t_flag->space_a, 1, res, t_flag);
}

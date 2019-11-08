/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:06:09 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/08 15:32:56 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_u(va_list arg, int *res, t_printf *t_flag)
{
	long long	nb;
	int			size;

	t_flag->conv = 0;
	nb = (long long)va_arg(arg, unsigned int);
	t_flag->size = ft_strlen(ft_itoa(nb));
	ft_update_value(t_flag, ((nb < 0) ? 1 : 0), NUMB);
	ft_handle_spaces(res, t_flag, 1, ((nb < 0) ? 1 : 0));
	if (t_flag->flag == 1 && nb == 0)
		return ;
	if (t_flag->flag == 2 && nb == 0)
	{
		if (t_flag->space_a > 0)
			ft_space(t_flag->space_a + 1, 1, res, t_flag);
		if (t_flag->size == 1 && t_flag->space_b > 0)
			*res++;
		return ;
	}
	if (t_flag->flag == 3 && nb == 0)
	{
		if (t_flag->size == 1 && t_flag->space_b > 0)
			*res++;
		return ;
	}
	ft_putnbr_u_fd(nb, 1);
	*res += t_flag->size;
	if (t_flag->space_a > 0)
		ft_space(t_flag->space_a, 1, res, t_flag);
}

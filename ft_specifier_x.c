/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:49:50 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/08 16:00:27 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_x(va_list arg, int *res, t_printf *t_flag)
{
	long long p;
	char *tmp;

	t_flag->conv = 0;
	p = va_arg(arg, unsigned int);
	tmp = ft_itoa_base(p, MIN);
	t_flag->size = ft_strlen(tmp);
	ft_update_value(t_flag, 0, ADDR);
	ft_handle_spaces(res, t_flag, 1, 0);
	if (t_flag->flag == 2 && p == 0)
	{
		if (t_flag->space_a > 0)
			ft_space(t_flag->space_a, 1, res, t_flag);
		if (t_flag->size == 1 && t_flag->space_b > 0)
			ft_space(t_flag->space_a + 2, 1, res, t_flag);
		return ;
	}
	if (t_flag->flag == 3 && p == 0)
	{
		if (t_flag->space_a > 0)
			ft_space(t_flag->space_a, 1, res, t_flag);
		if (t_flag->size == 1 && t_flag->space_b > 0)
			ft_space(t_flag->space_a + 2, 1, res, t_flag);
		return ;
	}
	ft_putstr_fd(tmp, 1);
	*res += ft_strlen(tmp);
	free(tmp);
	if (t_flag->space_a > 0)
		ft_space(t_flag->space_a, 1, res, t_flag);
}
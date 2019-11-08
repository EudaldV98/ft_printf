/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:47:35 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/08 15:26:12 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_p(va_list arg, int *res, t_printf *t_flag)
{
	long long	p;
	char		*tmp;

	t_flag->conv = 0;
	p = va_arg(arg, long long);
	if (!p && t_flag->fl_z)
		ft_putstr_fd("0x", 1);
	tmp = ft_itoa_base(p, MIN);
	t_flag->size = ft_strlen(tmp);
	if (t_flag->fl_point && !p)
		t_flag->flag = 7;
	ft_update_value(t_flag, 0, PADD);
	ft_handle_spaces(res, t_flag, 1, 0);
	if ((p || (!p && !t_flag->fl_z)) && t_flag->flag != 7)
		ft_putstr_fd("0x", 1);
	*res += 2;
	if (t_flag->fl_point && p == 0 && t_flag->flag != 7)
		return ;
	ft_putstr_fd(tmp, 1);
	*res += ft_strlen(tmp);
	free(tmp);
	if (t_flag->space_a > 0)
		ft_space(t_flag->space_a, 1, res, t_flag);
}

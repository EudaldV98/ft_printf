/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:06:17 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/08 12:16:44 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_falg_point(int *res, t_printf *t_flag, char *str, int *i)
{
	int nb;

	*i++;
	nb = ft_atoi(str);
	t_flag->fl_point = 1;
	if (nb >= 1)
		t_flag->width = nb;
	else
		t_flag->flag = 1;
	if (t_flag->fl_z_before > t_flag->width)
		t_flag->flag = 2;
	if (!ft_isdigit(str[0]))
		t_flag->flag = 3;
	else if (t_flag->fl_z_before)
		t_flag->flag = 4;
	if (nb == 0 && ft_isdigit(str[0]))
		*i++;
	else if (ft_isdigit(str[0]))
		*i += ft_strlen(ft_itoa(nb));
}

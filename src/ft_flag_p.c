/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:06:17 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/12 16:58:51 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_flag_p(int *res, t_printf *t_flag, char *str, int *i)
{
	int nb;

	*i += 1;
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
		*i += 1;
	else if (ft_isdigit(str[0]))
		*i += ft_strlen_nb(nb);
}

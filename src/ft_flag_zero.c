/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:01:10 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/13 16:49:54 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_flag_zero(int *res, t_printf *t_flag, int *i)
{
	if (!t_flag->fl_min)
		t_flag->fl_z = 1;
	else
		t_flag->flag = 5;
	*i += 1;
}

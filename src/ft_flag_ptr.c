/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:12:35 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/09 20:04:35 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_flag_ptr(va_list arg, int *res, t_printf *t_flag)
{
	if (!t_flag->fl_star)
		t_flag->space_b = va_arg(arg, int);
	else
		t_flag->fl_z_before = va_arg(arg, int);
	t_flag->fl_star++;
}

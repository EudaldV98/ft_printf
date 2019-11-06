/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:21:02 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/06 15:55:57 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_c(va_list arg, int *res, t_printf *t_flag)
{
	char c;

	t_flag->conv = 0;
	c = va_arg(arg, int);
	ft_update_value(t_flag, 0);
	ft_handle_space(res, t_flag, 1, 0);
	if (c)
		ft_putchar_fd(c, 1);
	else
		write(1, "\0", 1);
	*res++;
}

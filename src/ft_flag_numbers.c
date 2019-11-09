/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:39:54 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/09 20:04:23 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_flag_numbers(char *str, t_printf *t_flag, int *i)
{
	int nb;

	nb = ft_atoi(str);
	if (nb >= 1)
	{
		if (t_flag->fl_z && !t_flag->fl_z_before)
			t_flag->fl_z_before = nb;
		else
			t_flag->space_b = nb;
	}
	if (nb == 0 && ft_isdigit(str[0]))
		*i += 1;
	else if (ft_isdigit(str[0]))
		*i += ft_strlen_nb(nb);
}

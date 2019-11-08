/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:57:35 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/08 12:00:44 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_minus(int *res, t_printf *t_flag, char *str, int *i)
{
	int nb;

	if (str[0] == '0')
		t_flag->flag = 5;
	nb = ft_atoi(str);
	t_flag->fl_min = 1;
	if (nb < 1)
		t_flag->space_a = nb;
	else
		t_flag->flag = 1;
	if (nb == 0 && ft_isdigit(str[0]))
		*i++;
	else if (ft_isdigit(str[0]))
		*i += ft_strlen(ft_itoa(nb));
}

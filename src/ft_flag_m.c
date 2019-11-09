/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:57:35 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/09 20:04:26 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_flag_m(int *res, t_printf *t_flag, char *str, int *i)
{
	int nb;

	if (str[0] == '0')
		t_flag->flag = 5;
	nb = ft_atoi(str);
	t_flag->fl_min = 1;
	if (nb > 1)
		t_flag->space_a = nb;
	else
		t_flag->flag = 1;
	if (nb == 0 && ft_isdigit(str[0]))
		*i += 1;
	else if (ft_isdigit(str[0]))
		*i += ft_strlen_nb(nb);
}

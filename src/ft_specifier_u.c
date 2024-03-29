/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:49:10 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/19 16:05:57 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

t_count		ft_specifier_u(va_list aux, t_count cmp)
{
	long	nb;

	nb = va_arg(aux, unsigned int);
	if (nb < 0)
		nb = nb + 4294967295;
	cmp.str = ft_itoa((long)nb);
	return (cmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:46:34 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/19 16:06:04 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

t_count		ft_specifier_d(va_list aux, t_count cmp)
{
	int		nb;

	nb = va_arg(aux, int);
	cmp.str = ft_itoa((int)nb);
	return (cmp);
}

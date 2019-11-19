/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:44:29 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/19 16:05:56 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

t_count		ft_specifier_x(t_count cmp, long long nb, char c)
{
	char	*min;
	char	*maj;
	int		size;

	min = "0123456789abcdef";
	maj = "0123456789ABCDEF";
	nb = (nb < 0) ? -nb : nb;
	size = ft_strlen_nb(nb, 16);
	while (--size >= 0)
	{
		if (c == 'x')
			cmp.str[size] = min[nb % 16];
		else
			cmp.str[size] = maj[nb % 16];
		nb /= 16;
	}
	return (cmp);
}

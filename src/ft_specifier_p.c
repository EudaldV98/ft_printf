/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:42:00 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/19 16:06:01 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

t_count		ft_specifier_p(t_count cmp, long long nb)
{
	char	*min;
	int		size;

	min = "0123456789abcdef";
	nb = (nb < 0) ? -nb : nb;
	size = ft_strlen_nb(nb, 16) + 2;
	cmp.str[0] = '0';
	cmp.str[1] = 'x';
	while (--size >= 2)
	{
		cmp.str[size] = min[nb % 16];
		nb /= 16;
	}
	return (cmp);
}

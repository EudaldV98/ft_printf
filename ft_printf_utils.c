/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:49:43 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/26 19:39:34 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_strlen_nb(long nb, int base)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	if (nb < 0)
		len = 1;
	if (nb < 0)
		nb *= -1;
	while (nb >= 1)
	{
		nb /= base;
		len++;
	}
	return (len);
}

int		ft_is_convert(char c)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 's' || c == 'p' || c == 'x'
			|| c == 'X' || c == 'u')
		return (1);
	return (0);
}

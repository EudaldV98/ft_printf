/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:33:02 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/24 22:04:58 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_struct	ft_specifier_x(t_struct ret, long long nb, char c)
{
	char *min;
	char *caps;
	char size;

	caps = CAPS;
	min = MINU;
	if (nb < 0)
		nb *= -1;
	size = ft_strlen_nb(nb, 16);
	while (--size >= 0)
	{
		if (c == 'x')
			ret.str[size] = min[nb % 16];
		else
			ret.str[size] = caps[nb % 16];
		nb /= 16;
	}
	return (ret);
}

t_struct	ft_specifier_p(t_struct ret, long long nb)
{
	char	*min;
	int		size;

	min = MINU;
	if (nb < 0)
		nb *= -1;
	size = ft_strlen_nb(nb, 16) + 2;
	ret.str[0] = '0';
	ret.str[1] = 'x';
	while (--size >= 2)
	{
		ret.str[size] = min[nb % 16];
		nb /= 16;
	}
	return (ret);
}

t_struct	ft_specifier_hex(va_list arg, t_struct ret, char c)
{
	long long	nb;
	int			size;

	nb = va_arg(arg, long long);
	size = ft_strlen_nb(nb, 16);
	size = (c == 'p') ? size + 2 : size;
	if (!(ret.str = malloc(sizeof(char) * (size + 1))))
	{
		ret.str = NULL;
		return (ret);
	}
	ret.str[size] = '\0';
	if (c == 'p')
		ret = ft_specifier_p(ret, nb);
	else
		ret = ft_specifier_x(ret, nb, c);
	return (ret);
}

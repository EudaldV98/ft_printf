/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:20:07 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/24 22:07:27 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_struct	ft_specifier_u(va_list arg, t_struct ret)
{
	long i;

	i = va_arg(arg, unsigned int);
	if (i < 0)
		i = i + 4294967295;
	ret.str = ft_itoa((long)i);
	return (ret);
}

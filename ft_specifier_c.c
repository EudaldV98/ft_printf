/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:14:43 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/24 21:34:29 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_struct	ft_specifier_c(va_list arg, t_struct ret)
{
	unsigned char	c;

	c = va_arg(arg, int);
	if ((ret.str = malloc(sizeof(char) * 2)))
	{
		ret.str[0] = c;
		ret.str[1] = '\0';
		return (ret);
	}
	ret.str = NULL;
	return (ret);
}

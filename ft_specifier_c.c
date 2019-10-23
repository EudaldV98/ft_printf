/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:14:43 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/23 18:45:14 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
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

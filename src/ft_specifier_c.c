/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:50:35 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/19 16:06:06 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

t_count		ft_specifier_c(va_list aux, t_count cmp)
{
	unsigned char	c;

	c = va_arg(aux, int);
	cmp.len = (c == 0) ? cmp.len + 1 : cmp.len;
	if ((cmp.str = malloc(sizeof(char) * 2)))
	{
		cmp.str[0] = c;
		cmp.str[1] = '\0';
		return (cmp);
	}
	cmp.str = NULL;
	return (cmp);
}

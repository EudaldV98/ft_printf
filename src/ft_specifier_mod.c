/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:04:25 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/19 16:06:02 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

t_count		ft_specifier_mod(va_list au, t_count cmp)
{
	if (!(cmp.str = malloc(sizeof(char) * 2)))
	{
		cmp.str = NULL;
		return (cmp);
	}
	cmp.str[0] = '%';
	cmp.str[1] = '\0';
	return (cmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_xp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:04:05 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/22 15:47:32 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

t_count		ft_specifier_xp(va_list aux, t_count cmp, char c)
{
	long long	nb;
	int			size;

	nb = (c == 'p') ? va_arg(aux, long long) : va_arg(aux, unsigned int);
	size = ft_strlen_nb(nb, 16);
	size = (c == 'p') ? size + 2 : size;
	if (!(cmp.str = malloc(sizeof(char) * (size + 1))))
	{
		cmp.str = NULL;
		return (cmp);
	}
	cmp.str[size] = '\0';
	if (c == 'p')
		cmp = ft_specifier_p(cmp, nb);
	else
		cmp = ft_specifier_x(cmp, nb, c);
	return (cmp);
}

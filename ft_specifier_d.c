/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:22:20 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/24 21:34:15 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_struct	ft_spcifier_d(va_list arg, t_struct ret)
{
	int		i;

	i = va_arg(arg, int);
	ret.str = ft_itoa((int)i);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:22:20 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/23 17:55:58 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

t_struct	ft_spcifier_d(va_list arg, t_struct ret)
{
	int		i;

	i = va_arg(arg, int);
	ret.str = ft_itoa((int)i);
	return (ret);
}

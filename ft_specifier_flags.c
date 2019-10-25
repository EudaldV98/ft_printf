/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:43:58 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/25 17:27:03 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_struct	ft_specifier_flags(va_list arg, t_struct ret, char c, const char *s)
{
	t_struct tmp;

	tmp = ret;
	if (c == '*')
		ret = ft_flag_pointer(arg, s, ret);
	else if (c == '.')
		ret = ft_flag_point(arg, ret, s);
	else if (c == '-')
		ret = ft_flag_minus(arg, ret, s);
	return (ret);
}

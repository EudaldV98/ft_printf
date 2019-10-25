/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:56:56 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/25 17:11:57 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_struct	ft_flag_pointer(va_list arg, const char *s, t_struct ret)
{
	int i;

	i = ret.i + 2;
	if (s[i] == '.')
	{
		ret.i = i - 1;
		ret = ft_flag_point(arg, ret, s);
		i++;
		while (s[i] >= '0' && s[i + 1] <= '9')
			i++;
		if (ft_is_convert(s[i + 1]) == 1)
			i++;
		else if (s[i + 1] >= '0' && s[i + 1] <= '9')
		{
			i++;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
	}
	if (ft_is_convert(s[i]) == 1)
	{
		ret.space = va_arg(arg, int);
		ret.i = i - 1;
	}
	return (ret);
}

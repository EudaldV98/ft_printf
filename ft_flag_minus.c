/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:11:18 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/26 18:19:30 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_struct	ft_flag_minus(va_list arg, t_struct ret, const char *s)
{
	int i;

	i = ret.i + 2;
	if (s[i] == '*')
	{
		ret.i++;
		ret = ft_flag_pointer(arg, (const char *)s, ret);
		ret.space = (ret.space < 0) ? ret.space : -ret.space;
	}
	if (s[i] == '.')
	{
		ret.i++;
		ret = ft_flag_point(arg, ret, s);
	}
	else if (s[i] >= '0' && s[i] <= '9')
	{
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		if (ft_is_convert(s[i]) == 1)
		{
			ret.space = -ft_atoi((char *)&s[ret.i + 2]) - 1;
			ret.i = i - 1;
		}
		if (s[i] == '.')
		{
			ret.space = -ft_atoi((char *)&s[ret.i + 2]);
			ret.i = i - 1;
			ret = ft_flag_point(arg, ret, s);
		}
	}
	return (ret);
}

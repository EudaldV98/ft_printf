/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:10:17 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/25 17:11:00 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_struct	ft_flag_point(va_list arg, t_struct ret, const char *s)
{
	int i;

	i = ret.i + 2;
	if (s[i] == '*')
	{
		if (ft_is_convert(s[i + 1]) == 1)
		{
			ret.zero = va_arg(arg, int);
			ret.i += 2;
		}
	}
	else if ((s[i] >= '0' && s[i] <= '9') || ft_is_convert(s[i]))
	{
		ret.i = (s[i] >= '0' && s[i] <= '9') ? i : ret.i + 1;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		if (ft_is_convert(s[i]))
			ret.zero = ft_atoi((char *)&s[ret.i]);
		ret.i = i - 1;
	}
	return (ret);
}

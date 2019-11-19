/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:00:50 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/19 16:34:59 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

t_count		ft_flags(va_list aux, t_count cmp, char c, char *s)
{
	if (c == '*')
		cmp = ft_flag_ptr(aux, s, cmp);
	else if (c == '.')
		cmp = ft_flag_p(aux, cmp, s);
	else if (c == '0')
		cmp = ft_flag_z(aux, cmp, s);
	else if (c == '-')
		cmp = ft_flag_m(aux, cmp, s);
	else if (c >= '0' && c <= '9')
		cmp = ft_flag_nb(aux, cmp, s);
	return (cmp);
}

t_count		ft_switch_flag(va_list aux, t_count cmp, const char *s)
{
	cmp.space = cmp.zero;
	cmp = ft_flag_p(aux, cmp, s);
	if (cmp.zero < 0)
		cmp.zero = cmp.space;
	return (cmp);
}

t_count		ft_flag_ptr(va_list aux, const char *s, t_count cmp)
{
	int		k;

	k = cmp.i + 2;
	if (s[k] == '.')
	{
		cmp.i = k++ - 1;
		cmp.space = va_arg(aux, int);
		cmp = ft_flag_p(aux, cmp, s);
		while (s[k] >= '0' && s[k] <= '9')
			k++;
		if (ft_convertible(s[k + 1]) == 1)
			k++;
	}
	else if (ft_convertible(s[k]) == 1)
	{
		cmp.space = va_arg(aux, int);
		cmp.i = k - 1;
		return (cmp);
	}
	return (cmp);
}

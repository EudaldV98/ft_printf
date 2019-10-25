/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:34:08 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/25 18:04:47 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_struct	ft_print_flag(t_struct ret, int sign)
{
	int a;

	if (ret.space > 0 && sign == 1)
		while (ret.space-- > 0)
			ft_putchar_fd(' ', 1);
	if (ret.zero > 0 && ret.str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		ret.zero++;
		a = ft_strlcpy(ret.str, &ret.str[1], ft_strlen(ret.str));
		ret.len++;
	}
	if (ret.zero > 0)
		while (ret.zero-- > 0)
			ft_putchar_fd('0', 1);
	return (ret);
}

t_struct	ft_print_flag_back(t_struct ret, int sign)
{
	if (sign == -1 && ret.space > 0)
		while (ret.space-- > 0)
			ft_putchar_fd(' ', 1);
	return (ret);
}

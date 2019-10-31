/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:59:49 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/31 16:56:43 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*ft_init_struct(void)
{
	t_printf	*t_flag;

	if (!(t_flag = malloc(sizeof(t_printf))))
		return (NULL);
	t_flag->fl_min = 0;
	t_flag->space_a = 0;
	t_flag->space_b = 0;
	t_flag->fl_z = 0;
	t_flag->width = -1;
	t_flag->conv = 1;
	t_flag->size = 0;
	t_flag->fl_point = 0;
	t_flag->pcent = 0;
	t_flag->fl_star = 0;
	return (t_flag);
}

int			ft_is_flag(char c, t_printf *t_flag, int *i)
{
	if (t_flag->conv == 0)
	{
		*i += 1;
		return (0);
	}
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'x' ||
		c == 'X' || c == 'p' || c == 'u' || c == '%' || c == '-' || c == '0' ||
		c == '.' || c == '*' || c == ' ' || (c > '0' && c <= '9'))
		return (1);
	return (0);
}



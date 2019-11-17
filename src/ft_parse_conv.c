/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:59:49 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/17 20:27:28 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_printf	*ft_init_struct(void)
{
	t_printf	*t_flag;

	if (!(t_flag = malloc(sizeof(t_printf))))
		return (NULL);
	t_flag->fl_min = 0;
	t_flag->fl_z = 0;
	t_flag->fl_point = 0;
	t_flag->fl_star = 0;
	t_flag->space_a = 0;
	t_flag->space_b = 0;
	t_flag->fl_z_before = 0;
	t_flag->width = -1;
	t_flag->conv = 1;
	t_flag->size = -1;
	t_flag->pcent = 0;
	t_flag->flag = 0;
	t_flag->scase = 0;
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
		c == 'X' || c == 'u' || c == '%' || c == '-' || c == '0' || c == '.' ||
		c == '*' || c == ' ' || (c > '0' && c <= '9'))
		return (1);
	return (0);
}

void		ft_parse_conv(int *i, const char *str, va_list arg, int *res)
{
	t_printf	*t_flag;

	t_flag = ft_init_struct();
	while (ft_is_flag(str[*i], t_flag, i))
	{
		*i += 1;
		str[*i] == '0' ? ft_flag_zero(res, t_flag, i) : 0;
		str[*i] > '0' && str[*i] <= '9' ?
		ft_flag_numbers((char *)(str + *i), t_flag, i) : 0;
		str[*i] == '-' ? ft_flag_m(res, t_flag, (char*)(str + *i + 1), i) : 0;
		str[*i] == '.' ? ft_flag_p(res, t_flag, (char*)(str + *i + 1), i) : 0;
		str[*i] == '*' ? ft_flag_ptr(arg, i, t_flag, (char*)(str + *i + 1)) : 0;
		str[*i] == 'c' ? ft_specifier_c(arg, res, t_flag) : 0;
		str[*i] == 's' ? ft_specifier_s(arg, res, t_flag) : 0;
		str[*i] == 'p' ? ft_specifier_p(arg, res, t_flag) : 0;
		str[*i] == 'd' ? ft_specifier_d(arg, res, t_flag) : 0;
		str[*i] == 'i' ? ft_specifier_d(arg, res, t_flag) : 0;
		str[*i] == 'u' ? ft_specifier_u(arg, res, t_flag) : 0;
		str[*i] == 'x' ? ft_specifier_x(arg, res, t_flag) : 0;
		str[*i] == 'X' ? ft_specifier_xmaj(arg, res, t_flag) : 0;
		str[*i] == '%' ? ft_specifier_mod(res, t_flag) : 0;
	}
	free(t_flag);
}

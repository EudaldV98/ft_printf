/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:19:48 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/23 19:34:41 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

t_struct	ft_print_args(t_struct ret)
{
	/*int sign;

	if ((ret.zero -= ft_strlen(ret.str)) < 0)
		ret.zero = 0;
	sign = (ret.space > 0) ? 1 : -1;
	ret.space = (sign == -1) ? -ret.space : ret.space;
	ret.space = ret.space - ft_strlen(ret.str) - ret.zero;
	ret.space = (ret.space > 0) ? ret.space : 0;
	ret.space = (ret.str[0] == '-' && ret.space > 0) ?
				ret.space - 1 : ret.space;
	ret.space = (ret.str[0] == '-' && ret.space < 0) ?
				ret.space + 1 : ret.space;*/
	ret.len = ret.len + ft_strlen(ret.str) + ret.space + ret.zero;
	//ret = ft_print_flag(ret, sign);
	ft_putstr_fd(ret.str, 1);
	//ret = ft_print_flag(ret, sign);
	ret.zero = 0;
	ret.space = 0;
	return (ret);
}

t_struct	ft_start_specifier(va_list arg, const char *format, t_struct ret)
{
	//ret = ft_flags(arg, ret, format[ret.i + 1], format);
	if (format[ret.i + 1] == 'c')
		ret = ft_specifier_c(arg, ret);
	else if (format[ret.i + 1] == 's')
		ret = ft_specifier_s(arg, ret);
	else if (format[ret.i + 1] == 'd' || format[ret.i + 1] == 'i')
		ret = ft_spcifier_d(arg, ret);
	else if (format[ret.i + 1] == '')
	if (ret.str != NULL)
		ret.i++;
	ret = ft_print_args(ret);
	ret.str = NULL;
	return (ret);
}

t_struct	ft_init_struct(t_struct new, int n)
{
	if (n != 1)
	{
		new.i = 0;
		new.len = 0;
		new.str = NULL;
	}
	new.space = 0;
	new.zero = 0;
	return (new);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	t_struct	ret;
	int			len;
	int			j;

	ret.str = NULL;
	va_start(arg, format);
	ret = ft_init_struct(ret, 0);
	len = ft_strlen(format);
	while (ret.i < len)
	{
		ret = ft_init_struct(ret, 1);
		j = ret.i;
		if (format[ret.i] == '%')
		{
			ret = ft_start_specifier(arg, format, ret);
			if (ret.i == j)
				ft_putchar_fd('%', 1);
		}
		else
		{
			ft_putchar_fd(format[ret.i], 1);
			ret.len++;
		}
		ret.i++;
	}
	free(ret.str);
	va_end(arg);
	return (ret.len);
}

int		main(int argc, const char *argv[])
{
	char c = 'A';
	char *s = "World";
	int i = 2123;

	//printf("Hello!! %-5d %c %s \n", i, 65, s);
	ft_printf("Hello!! %c %i %s ", c, i, s);
	return (0);
}

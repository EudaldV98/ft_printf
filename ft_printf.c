/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:19:48 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/21 21:29:48 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"


void	ft_start_specifier(char sp, va_list arg)
{
	unsigned int	i;
	char			*s;

	if (sp == 'c')
	{
		i = va_arg(arg, int);
		ft_putchar_fd(i, 1);
		return ;
	}
	else if (sp == 's')
	{
		s = va_arg(arg, char *);
		ft_putstr_fd(s, 1);
		return ;
	}
	else if (sp == 'd' || sp == 'i')
	{
		i = va_arg(arg, int);
		ft_putnbr_fd(i, 1);
		return ;
	}
}

int		ft_printf(const char *format, ...)
{
	char			*tmp;
	unsigned int	i;
	va_list			arg;

	va_start(arg, format);
	i = 0;
	tmp = (char *)format;
	if (!tmp)
		return (0);
	while (tmp[i])
	{
		while (tmp[i] != '%' && tmp[i])
		{
			ft_putchar_fd(tmp[i], 1);
			i++;
		}
		if (tmp[i] == '%')
		{
			ft_start_specifier(tmp[i + 1], arg);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (1);
}

int		main(int argc, const char *argv[])
{
	char c = 'A';
	char *s = "World";
	int i = 2123;
	
	ft_printf("Hello!! %i %c %s ", i, c, s);
	return (0);
}
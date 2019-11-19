/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:03:06 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/19 16:48:52 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

t_count			ft_print_front_flag(t_count cmp, int neg, char *s)
{
	int		a;

	cmp = ft_except_p(cmp, s);
	if (cmp.space > 0 && neg == 1)
		while (cmp.space-- > 0)
			write(1, " ", 1);
	if (cmp.zero > 0 && cmp.str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		a = ft_strlcpy(cmp.str, &cmp.str[1], ft_strlen(cmp.str));
	}
	if (s[cmp.i] != 's' || (s[cmp.i] == 's' && cmp.check == 1))
		while (cmp.zero-- > 0)
			write(1, "0", 1);
	if (s[cmp.i] == 'c' && cmp.str[0] == '\0')
	{
		ft_putchar_fd('\0', 1);
	}
	else
		ft_putstr_fd(cmp.str, 1);
	return (cmp);
}

t_count			ft_print_back_flag(t_count cmp, int neg)
{
	if (neg == -1 && cmp.space > 0)
		while (cmp.space-- > 0)
			write(1, " ", 1);
	return (cmp);
}

t_count			ft_print_arg(t_count cmp, char *s)
{
	const int			neg = (cmp.space > 0) ? 1 : -1;

	cmp = (s[cmp.i] == 's') ? ft_reduc_str(cmp, s) : ft_check_null_str(cmp, s);
	if (s[cmp.i] == 'c' && cmp.check == 2)
		cmp.zero = 0;
	if (cmp.str[0] == '-' && (size_t)cmp.zero >= ft_strlen(cmp.str) &&
		(cmp.check == 2 || cmp.check == 3))
		cmp.zero++;
	if (s[cmp.i] != 's' || cmp.check != 2 || cmp.zero != 0)
		cmp.zero -= ft_strlen(cmp.str);
	if (cmp.zero < 0)
		cmp.zero = 0;
	if (s[cmp.i] == 's' && cmp.zero != 0 && cmp.check != 1)
		cmp.zero = 0;
	cmp.space = (neg == -1) ? -cmp.space : cmp.space;
	if (s[cmp.i] == 's' && cmp.zero == UMAX)
		cmp.space++;
	cmp.space = cmp.space - ft_strlen(cmp.str) - cmp.zero;
	cmp.space = (cmp.space < 0) ? 0 : cmp.space;
	if (s[cmp.i] == 's' && cmp.str[0] == '\0' && cmp.check == 3)
		cmp.space = 0;
	cmp.len = cmp.len + ft_strlen(cmp.str) + cmp.space + cmp.zero;
	cmp = ft_print_front_flag(cmp, neg, s);
	cmp = ft_print_back_flag(cmp, neg);
	return (cmp);
}

t_count			ft_check(va_list aux, const char *s, t_count cmp)
{
	const int		save = cmp.i;

	cmp = ft_flags(aux, cmp, s[cmp.i + 1], (char *)s);
	if (s[cmp.i + 1] == 'd' || s[cmp.i + 1] == 'i')
		cmp = ft_specifier_d(aux, cmp);
	else if (s[cmp.i + 1] == 'u')
		cmp = ft_specifier_u(aux, cmp);
	else if (s[cmp.i + 1] == 'c')
		cmp = ft_specifier_c(aux, cmp);
	else if (s[cmp.i + 1] == 's')
		cmp = ft_specifier_s(aux, cmp);
	else if (s[cmp.i + 1] == 'x' || s[cmp.i + 1] == 'X' || s[cmp.i + 1] == 'p')
		cmp = ft_specifier_xp(aux, cmp, s[cmp.i + 1]);
	else if (s[cmp.i + 1] == '%')
		cmp = ft_specifier_mod(aux, cmp);
	if (cmp.str != NULL)
		cmp.i++;
	if ((cmp.i = (cmp.str == NULL) ? save : cmp.i) == save)
		return (cmp);
	cmp = ft_print_arg(cmp, (char*)s);
	cmp = ft_init_count(cmp, 1);
	ft_strdel(&cmp.str);
	return (cmp);
}

int				ft_printf(const char *str, ...)
{
	va_list		aux;
	t_count		cmp;
	int			len_str;
	int			k;

	cmp.str = NULL;
	va_start(aux, str);
	cmp = ft_init_count(cmp, 0);
	len_str = ft_strlen((char*)str);
	while (cmp.i < len_str)
	{
		cmp = ft_init_count(cmp, 1);
		k = cmp.i;
		if (str[cmp.i] == '%')
			cmp = ft_check(aux, str, cmp);
		else
		{
			ft_putchar_fd(str[cmp.i], 1);
			cmp.len++;
		}
		cmp.i++;
	}
	va_end(aux);
	return (cmp.len);
}

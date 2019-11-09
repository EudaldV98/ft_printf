/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:49:50 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/09 20:05:46 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_x_exception(long long ptr, int *res, t_printf *t_flag)
{
	if (t_flag->flag == 2 && ptr == 0)
	{
		if (t_flag->space_a > 0)
			ft_space(t_flag->space_a, 1, res, t_flag);
		if (t_flag->size == 1 && t_flag->space_b > 0)
			ft_space(t_flag->space_a + 2, 1, res, t_flag);
		return (1);
	}
	if (t_flag->flag == 3 && ptr == 0)
	{
		if (t_flag->space_a > 0)
			ft_space(t_flag->space_a, 1, res, t_flag);
		if (t_flag->size == 1 && t_flag->space_b > 0)
			ft_space(t_flag->space_a + 2, 1, res, t_flag);
		return (1);
	}
	return (0);
}

void	ft_specifier_x(va_list arg, int *res, t_printf *t_flag)
{
	long long	ptr;
	char		*tmp;

	t_flag->conv = 0;
	ptr = va_arg(arg, unsigned int);
	tmp = ft_itoa_base(ptr, MIN);
	t_flag->size = ft_strlen(tmp);
	ft_update_value(t_flag, 0, ADDR);
	ft_handle_spaces(res, t_flag, 1, 0);
	if (ft_x_exception(ptr, res, t_flag))
		return ;
	ft_putstr_fd(tmp, 1);
	*res += ft_strlen(tmp);
	if (t_flag->space_a > 0)
		ft_space(t_flag->space_a, 1, res, t_flag);
	free(tmp);
	tmp = NULL;
}

void	ft_specifier_xmaj(va_list aux, int *res, t_printf *t_flag)
{
	long long	ptr;
	char		*tmp;

	t_flag->conv = 0;
	ptr = va_arg(aux, unsigned int);
	tmp = ft_itoa_base(ptr, CAP);
	t_flag->size = ft_strlen(tmp);
	ft_update_value(t_flag, 0, ADDR);
	ft_handle_spaces(res, t_flag, 1, 0);
	if (ft_x_exception(ptr, res, t_flag))
		return ;
	ft_putstr_fd(tmp, 1);
	*res += ft_strlen(tmp);
	if (t_flag->space_a > 0)
		ft_space(t_flag->space_a, 1, res, t_flag);
	free(tmp);
	tmp = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:06:09 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/09 20:05:41 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_specifier_u(va_list aux, int *res, t_printf *t_flag)
{
	long long	nb;
	int			size_nb;

	t_flag->conv = 0;
	nb = (long long)va_arg(aux, unsigned int);
	t_flag->size = ft_strlen_lnb(nb);
	ft_update_value(t_flag, ((nb < 0) ? 1 : 0), NUMB);
	ft_handle_spaces(res, t_flag, 1, ((nb < 0) ? 1 : 0));
	if (ft_nb_exception(nb, res, t_flag))
		return ;
	ft_putnbr_u_fd(nb, 1);
	*res += t_flag->size;
	if (t_flag->space_a > 0)
		ft_space(t_flag->space_a, 1, res, t_flag);
}
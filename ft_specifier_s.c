/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:07:22 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/23 17:55:35 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

t_struct	ft_specifier_s(va_list arg, t_struct ret)
{
	char	*tmp;
	int		i;

	tmp = va_arg(arg, char*);
	if (!tmp || tmp == NULL)
	{
		if ((ret.str = malloc(sizeof(char) * 7)) != NULL)
			ret.str = "(null)";
		else
			ret.str = NULL;
		return (ret);
	}
	else
	{
		ret.str = ft_strdup(tmp);
		i = -1;
		while (tmp[++i])
		{
			ret.str[i] = tmp[i];
		}
		ret.str[i] = '\0';
	}
	return (ret);
}

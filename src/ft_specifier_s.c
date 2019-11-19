/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:52:06 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/19 16:05:59 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

t_count		ft_specifier_s(va_list aux, t_count cmp)
{
	char	*temp;
	int		i;

	temp = va_arg(aux, char*);
	if (!temp || temp == NULL)
	{
		if ((cmp.str = malloc(sizeof(char) * 7)) != NULL)
			i = ft_strlcpy(cmp.str, "(null)", 7);
		else
			cmp.str = NULL;
		return (cmp);
	}
	else
	{
		cmp.str = ft_strdup(temp);
		i = -1;
		while (temp[++i])
		{
			cmp.str[i] = temp[i];
		}
		cmp.str[i] = '\0';
	}
	return (cmp);
}

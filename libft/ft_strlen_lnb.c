/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_lnb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:49:12 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/08 17:49:44 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_lnb(long long nb)
{
	char	*lnb;
	int		size;

	lnb = ft_lgitoa(nb);
	size = ft_strlen(lnb);
	free(lnb);
	return (size);
}

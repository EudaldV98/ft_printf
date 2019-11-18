/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:33:17 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/18 16:20:28 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_nb(int nb)
{
	char	*lnb;
	int		size;

	lnb = ft_itoa(nb);
	size = ft_strlen(lnb);
	free(lnb);
	return (size);
}

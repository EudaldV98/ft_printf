/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:54:43 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/31 15:58:01 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define CAP "0123456789ABCDEF"
# define MIN "0123456789abcdef"
# define PTR 1
# define XADR 2
# define MXADR 3

typedef struct	s_printf
{
	int		fl_min;
	int		space_b;
	int		space_a;
	int		fl_z;
	int		fl_star;
	int		width;
	int		conv;
	int		size;
	int		fl_point;
	int		pcent;
}				t_printf;

#endif
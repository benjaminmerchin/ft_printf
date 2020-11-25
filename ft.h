/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 07:03:28 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/22 19:33:39 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_struct
{
	va_list			args;
	int				ret;
	int				i;
	int				num;
	char			*s;
	char			*str;
	unsigned long	p;
	int				neg_star;
	int				len;
	int				f_neg;
	char			f_zero;
	int				width;
	int				width_len;
	int				prec;
	int				prec_len;
}				t_struct;

#endif

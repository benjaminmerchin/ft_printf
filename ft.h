/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 07:03:28 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/11 07:15:53 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct	s_struct
{
	va_list	args;
	int		ret;
	int		i;
	int		num;
	char	*s;
	char	*str;
	int		len;
	int		f_neg;
	int		f_zero;
	int		width;
	int		width_len;
	int		prec;
	int		prec_len;
}				t_struct;

#endif

//%[flags][width][.precision][length]type

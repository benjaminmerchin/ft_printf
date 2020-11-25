/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 07:03:28 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/25 05:40:44 by bmerchin         ###   ########.fr       */
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

int				ft_printf(const char *str, ...);
void			parsor(t_struct *data);
void			parsor_flag(t_struct *data);
void			parsor_prec(t_struct *data);
void			parsor_width(t_struct *data);
void			init_struct(t_struct *data);
void			hq_pointer(t_struct *data);
void			hq_pointer2(t_struct *data, int i, int j);
void			ft_len_addr(unsigned long nb, t_struct *data);
void			ft_put_addr(unsigned long nbr, t_struct *data);
void			hq_hex(t_struct *data);
void			hq_hex2(t_struct *data, int i, int j);
void			hq_int(t_struct *data);
void			hq_int2(t_struct *data, int i, int j, int k);
void			hq_int3(t_struct *data, int i, int j, int k);
void			hq_s_c(t_struct *data);
void			shq_s_c(t_struct *data);
void			shq_s_c2(t_struct *data, int i, int j);
void			ft_len_hex(int nbr, t_struct *data);
void			ft_put_hex(int nbr, t_struct *data);
char			*ft_itoa_unsigned(unsigned int n, t_struct *data);
void			ft_itoa_fill_unsigned(char *str,
				unsigned long nbr, unsigned int i);
char			*ft_itoa(int n, t_struct *data);
void			ft_itoa_fill(char *str, long nbr, int i);
int				ft_intlen(long int nbr);
int				ft_strlen(const char *s);
int				ft_atoi(char *str);
void			ft_putstr(char *str, t_struct *data);
void			ft_putchar(char c, t_struct *data);

#endif

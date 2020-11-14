/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 07:30:11 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/14 21:57:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

// [flags][width][.precision][length]

typedef struct	s_struct
{
	va_list	args;
	int		ret;
	int		i;
	int		num;
	char	*s;
	char	*str;
	unsigned long p;
	int		len;
	int		f_neg;
	char	f_zero;
	int		width;
	int		width_len;
	int		prec;
	int		prec_len;
}				t_struct;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
/*	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}*/
	while (str[i] >= '0' && str[i] <= '9')
	{
/*		if (sign == 1 && nbr > 922337203685477580)
			return (-1);
		else if (nbr > 922337203685477580)
			return (0);*/
		nbr = nbr * 10 + str[i++] - '0';
	}
	return (nbr * sign);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_intlen(long int nbr)
{
	int i;

	i = 1;
	nbr /= 10;
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

void	ft_itoa_fill(char *str, long nbr, int i)
{
	int temp;

	temp = nbr % 10;
	str[i - 1] = temp + '0';
	nbr /= 10;
	if (nbr > 0)
		ft_itoa_fill(str, nbr, i - 1);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			sign;
	long int	nbr;

	i = 0;
	sign = 0;
	if (n < 0)
	{
		nbr = n;
		nbr *= -1;
		sign = 1;
		i++;
	}
	else
		nbr = n;
	if (!(str = malloc(sizeof(char) * (ft_intlen(nbr) + sign + 1))))
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	ft_itoa_fill(str + sign, nbr, ft_intlen(nbr));
	str[ft_intlen(nbr) + sign] = '\0';
	return (str);
}

void	ft_put_hex(int nbr, t_struct *data)
{
	char *base;
	long nb = (long)nbr;

	if (data->str[data->i] == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb < 0)
	{
		nb = 4294967296 + nb;
	}
	if (nb >= 16)
		ft_put_hex(nb / 16, data);
	ft_putchar(base[nb % 16]);
}

void	ft_len_hex(int nbr, t_struct *data)
{
	long nb = (long)nbr;

	if (nb < 0)
		nb = 4294967296 + nb;
	if (nb >= 16)
		ft_len_hex(nb / 16, data);
	data->len++;
}

void	shq_s_c(t_struct *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (data->s == NULL && data->str[data->i] == 's')
		data->s = "(null)";
	if (data->prec_len < 0)
		data->prec_len = ft_strlen(data->s);
	if (data->prec && ft_strlen(data->s) > data->prec_len)
		data->len = data->prec_len;
	else
		data->len = ft_strlen(data->s);
	while (data->width && i < data->width_len - data->len && !data->f_neg)
	{
		ft_putchar(data->f_zero);
		i++;
	}
	while (j < data->len)
		ft_putchar(data->s[j++]);
	while (data->width && i < data->width_len - data->len && data->f_neg)
	{
		ft_putchar(data->f_zero);
		i++;
	}
}

void	hq_s_c(t_struct *data)
{
	char c[2];
	
	if (data->str[data->i] == 's')
		data->s = va_arg(data->args, char *);
	if (data->str[data->i] == 'c')
	{
		c[0] = va_arg(data->args, int);
		c[1] = '\0';
		data->s = c;
	}
	shq_s_c(data);
}

void	hq_int(t_struct *data)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	data->s = ft_itoa(va_arg(data->args, int));
	if (data->prec && ft_strlen(data->s) < data->prec_len)
		data->len = data->prec_len;
	else
		data->len = ft_strlen(data->s);
	if (data->prec && data->prec_len == 0 && data->s[0] == '0' && data->s[1] == '\0')
	{
		data->s[0] = '\0';
		if (data->width_len > 0)
			i--;
	}
	if (data->width && data->prec && data->width_len >
	data->prec_len && ft_strlen(data->s) <= data->prec_len && data->s[0] == '-')
		i++;
	while (data->f_zero == ' ' && data->width && i < data->width_len - data->len && !data->f_neg)
	{
		ft_putchar(data->f_zero);
		i++;
	}
	while (data->f_zero == '0' && data->prec && data->width && i < data->width_len - data->len && !data->f_neg)
	{
		ft_putchar(' ');
		i++;
	}
	if (data->s[j] == '-')
	{
		ft_putchar('-');
		j++;
		k = -1;
	}
	while (data->f_zero == '0' && data->width && i < data->width_len - data->len && !data->f_neg)
	{
		ft_putchar(data->f_zero);
		i++;
	}
	while (data->prec && k < data->prec_len - ft_strlen(data->s))
	{
		ft_putchar('0');
		k++;
	}
	while (j < ft_strlen(data->s))
		ft_putchar(data->s[j++]);
	while (data->width && i < data->width_len - data->len && data->f_neg)
	{
		ft_putchar(' ');
		i++;
	}
	free(data->s);
}

void	hq_hex(t_struct *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->num = va_arg(data->args, int);
	ft_len_hex(data->num, data);
	while (!data->f_neg && j < data->width_len - data->prec_len && j < data->width_len - data->len)
	{
		if (data->f_zero != '0' || data->prec)
			ft_putchar(' ');
		else
			ft_putchar('0');
		j++;
	}
	while (i < data->prec_len - data->len)
	{
		ft_putchar('0');
		i++;
	}
	if (data->num == 0 && data->prec && data->prec_len == 0)
	{
		if (data->width_len > 0)
			ft_putchar(' ');
	}
	else
		ft_put_hex(data->num, data);
	while (data->f_neg && j < data->width_len - data->prec_len && j < data->width_len - data->len)
	{
		ft_putchar(' ');
		j++;
	}
}

void	ft_put_addr(unsigned long nbr)
{
	char *base;

	base = "0123456789abcdef";
	if (nbr >= 16)
		ft_put_addr(nbr / 16);
	ft_putchar(base[nbr % 16]);
}

void	ft_len_addr(unsigned long nb, t_struct *data)
{
	if (nb >= 16)
		ft_len_addr(nb / 16, data);
	data->len++;
}

void	hq_pointer(t_struct *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->p = (unsigned long)va_arg(data->args, unsigned long);	
	ft_len_addr(data->p, data);
	data->len += 2;
	while (!data->f_neg && i < data->width_len - data->len)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr("0x");
	while (data->prec && j < data->prec_len - data->len + 2)
	{
		ft_putchar('0');
		j++;
	}
	ft_put_addr(data->p);
	while (data->f_neg && i < data->width_len - data->len)
	{
		ft_putchar(' ');
		i++;
	}
}

void	init_struct(t_struct *data)
{
	data->len = 0;
	data->f_neg = 0;
	data->f_zero = ' ';
	data->width = 0;
	data->width_len = 0;
	data->prec = 0;
	data->prec_len = 0;
}

void	parsor_width(t_struct *data)
{
	data->width = 1;
	if (data->str[data->i] == '*')
	{	
		data->width_len = va_arg(data->args, int);
		data->i++;
	}
	else
	{
		data->width_len = ft_atoi(data->str + data->i);
		while (data->str[data->i] >= '0' && data->str[data->i] <= '9')
			data->i++;
	}
}

void	parsor_prec(t_struct *data)
{
	data->prec = 1;
	data->i++;
	if (data->str[data->i] == '*')
	{	
		data->prec_len = va_arg(data->args, int);
		data->i++;
	}
	else
	{

		data->prec_len = ft_atoi(data->str + data->i);
		while (data->str[data->i] >= '0' && data->str[data->i] <= '9')
			data->i++;
	}
}

void	parsor(t_struct *data)
{
	init_struct(data);
	data->i++;
	while (data->str[data->i] == '0' || data->str[data->i] == '-')
	{
		if (data->str[data->i] == '0')
			data->f_zero = '0';
		else
			data->f_neg = 1;
		data->i++;
	}
	if ((data->str[data->i] >= '1' && data->str[data->i] <= '9') ||
	data->str[data->i] == '*')
		parsor_width(data);
	if (data->str[data->i] == '.')
		parsor_prec(data);
	if (data->str[data->i] == 'd' || data->str[data->i] == 'i' || data->str[data->i] == 'u')
		hq_int(data);
	if (data->str[data->i] == 's' || data->str[data->i] == 'c')
		hq_s_c(data);
	if (data->str[data->i] == 'x' || data->str[data->i] == 'X')
		hq_hex(data);
	if (data->str[data->i] == 'p')
		hq_pointer(data);
	data->i++;
}

int		ft_printf(const char *str, ...)
{
	t_struct data;
	
	data.i = 0;
	data.ret = 0;
	data.str = (char *)str;
	va_start(data.args, str);
	while (str[data.i])
	{
		if (str[data.i] == '%')
			parsor(&data);
		else
		{
			write(1, &str[data.i], 1);
			data.i++;
		}
	}
	va_end(data.args);
	return (data.ret);
}
/*
int		main(int ac, char **av)
{
	(void)ac;
	ft_printf(av[4], atoi(av[1]), atoi(av[2]), -1, av[3]);
	printf("\n-----------------------\n");
	printf(av[4], atoi(av[1]), atoi(av[2]), -1, av[3]);
	printf("\n");
	printf("-----------------------\n");
	printf("%1d-----%.3d-----%.5d\n", atoi(av[1]), atoi(av[2]), atoi(av[3]));
	printf("-----------------------\n");
	printf("%5.s-----%.s-----%.5s\n", av[1], av[2], av[3]);
	ft_printf("%d\n", 1);
	return (0);
}
*/
// "%.2d oui %x yes %-10.*s\n"

/*
c char
s string
p pointer (address)
d int
i int mais si ca commence par 0 c'est en octal et si ca comence par 0x c'est en hexa
u unsigned int
x hex en min
X hex en maj
*/

//%[flags][width][.precision][length]type il y a un ordre pour les flag a respecter

//width ne tronque jamais une valeur
//length ne peut tronquer aue des string

/*
- alligne a gauche la sortie (droite par default) (on peut en mettre plusieures)
0 remplis de 0 au lieu de ' ' (espaces) (pac chez les string) (pas en meme temps que '-')
. flag de precision sur la longueur de chaine, differe cas d et s
* on va chercher le nombre avec va_args
*/

// Strategie : gerer les flagg pour un type et ensuite gerer tous les types
// Utiliser une maxi structure pour tout stocker
// lire, parse et ranger les infos des flagg dans un struct et ensuite print

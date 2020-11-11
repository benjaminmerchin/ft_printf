/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 07:30:11 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/11 06:23:37 by bmerchin         ###   ########.fr       */
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
	int		f_neg;
	int		f_zero;
	int		f_neg;
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

int		ft_len(long int nbr)
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
	if (!(str = malloc(sizeof(char) * (ft_len(nbr) + sign + 1))))
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	ft_itoa_fill(str + sign, nbr, ft_len(nbr));
	str[ft_len(nbr) + sign] = '\0';
	return (str);
}

void ft_put_d(int a)
{
	char *str;

	str = ft_itoa(a);
	ft_putstr(str);
	free(str);
}

void ft_put_hex(int nbr)
{
	char *base;
	long nb = (long)nbr;

	base = "0123456789abcdef";
	if (nb < 0)
	{
		nb = 4294967296 + nb;
	}
	if (nb >= 16)
		ft_put_hex(nb / 16);
	ft_putchar(base[nb % 16]);
}

void	parsor(t_struct *data)
{
	data->i++;
	if (data->str[data->i] == 'd')
	{
		data->num = va_arg(data->args, int);
		ft_put_d(data->num);
	}
	if (data->str[data->i] == 's')
	{
		data->s = va_arg(data->args, char *);
		ft_putstr(data->s);
	}
	if (data->str[data->i] == 'x')
	{
		data->num = va_arg(data->args, int);
		ft_put_hex(data->num);
	}
	data->i++;
}

int ft_printf(const char *str, ...)
{
	t_struct data;
	
	data.i = 0;
	data.ret = 1;
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

int main(int ac, char **av)
{
	(void)ac;
	ft_printf("%d oui %x yes %s\n", atoi(av[1]), atoi(av[2]), av[3]);
	printf("-----------------------\n");
	printf("%d oui %x yes %s\n", atoi(av[1]), atoi(av[2]), av[3]);	
/*	printf("-----------------------\n");
	printf("%1d-----%.3d-----%.5d\n", atoi(av[1]), atoi(av[2]), atoi(av[3]));
	printf("-----------------------\n");
	printf("%1s-----%.3s-----%.5s\n", av[1], av[2], av[3]);*/
	return (0);
}


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

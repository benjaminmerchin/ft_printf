/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 07:30:11 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/22 21:30:18 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c, t_struct *data)
{
	write(1, &c, 1);
	data->ret++;
}

void	ft_putstr(char *str, t_struct *data)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		data->ret++;
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
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
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

int		ft_intlen_unsigned(long unsigned int nbr)
{
	unsigned int i;

	i = 1;
	nbr /= 10;
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

void	ft_itoa_fill_unsigned(char *str, unsigned long nbr, unsigned int i)
{
	unsigned int temp;

	temp = nbr % 10;
	str[i - 1] = temp + '0';
	nbr /= 10;
	if (nbr > 0)
		ft_itoa_fill(str, nbr, i - 1);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char				*str;
	unsigned int		i;
	unsigned int		sign;
	unsigned long int	nbr;

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
	long nb;

	nb = (long)nbr;
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
	ft_putchar(base[nb % 16], data);
}

void	ft_len_hex(int nbr, t_struct *data)
{
	long nb;

	nb = (long)nbr;
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
	if (data->str[data->i] == 'c' && data->s[0] == '\0')
		i++;
	while (data->width && i < data->width_len - data->len && !data->f_neg)
	{
		ft_putchar(data->f_zero, data);
		i++;
	}
	while (j < data->len)
		ft_putchar(data->s[j++], data);
	if (data->str[data->i] == 'c' && data->s[0] == '\0')
		ft_putchar('\0', data);
	while (data->width && i < data->width_len - data->len && data->f_neg)
	{
		ft_putchar(data->f_zero, data);
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
	if (data->str[data->i] == '%')
	{
		c[0] = '%';
		c[1] = '\0';
		data->s = c;
	}
	if (data->f_neg)
		data->f_zero = ' ';
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
	if (data->str[data->i] == 'u')
		data->s = ft_itoa_unsigned(va_arg(data->args, unsigned int));
	else
		data->s = ft_itoa(va_arg(data->args, int));
	if (data->prec && ft_strlen(data->s) < data->prec_len)
		data->len = data->prec_len;
	else
		data->len = ft_strlen(data->s);
	if (data->prec && data->prec_len == 0 &&
			data->s[0] == '0' && data->s[1] == '\0')
	{
		data->s[0] = '\0';
		if (data->width_len > 0)
			i--;
	}
	if (data->width && data->prec && data->width_len >
	data->prec_len && ft_strlen(data->s) <= data->prec_len && data->s[0] == '-')
		i++;
	while (data->f_zero == ' ' && data->width &&
			i < data->width_len - data->len && !data->f_neg)
	{
		ft_putchar(data->f_zero, data);
		i++;
	}
	while (data->f_zero == '0' && data->prec && data->width &&
			i < data->width_len - data->len && !data->f_neg)
	{
		ft_putchar(' ', data);
		i++;
	}
	if (data->s[j] == '-')
	{
		ft_putchar('-', data);
		j++;
		k = -1;
	}
	while (data->f_zero == '0' && data->width &&
			i < data->width_len - data->len && !data->f_neg)
	{
		ft_putchar(data->f_zero, data);
		i++;
	}
	while (data->prec && k < data->prec_len - ft_strlen(data->s))
	{
		ft_putchar('0', data);
		k++;
	}
	while (j < ft_strlen(data->s))
		ft_putchar(data->s[j++], data);
	while (data->width && i < data->width_len - data->len && data->f_neg)
	{
		ft_putchar(' ', data);
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
	while (!data->f_neg && j < data->width_len - data->prec_len &&
			j < data->width_len - data->len)
	{
		if (data->f_zero != '0' || data->prec)
			ft_putchar(' ', data);
		else
			ft_putchar('0', data);
		j++;
	}
	while (i < data->prec_len - data->len)
	{
		ft_putchar('0', data);
		i++;
	}
	if (data->num == 0 && data->prec && data->prec_len == 0)
	{
		if (data->width_len > 0)
			ft_putchar(' ', data);
	}
	else
		ft_put_hex(data->num, data);
	while (data->f_neg && j < data->width_len - data->prec_len &&
			j < data->width_len - data->len)
	{
		ft_putchar(' ', data);
		j++;
	}
}

void	ft_put_addr(unsigned long nbr, t_struct *data)
{
	char *base;

	base = "0123456789abcdef";
	if (nbr >= 16)
		ft_put_addr(nbr / 16, data);
	ft_putchar(base[nbr % 16], data);
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
	data->p = va_arg(data->args, unsigned long);
	ft_len_addr(data->p, data);
	data->len += 2;
	if (data->p == 0 && data->prec == 1 &&
			(data->neg_star == 1 || data->prec_len == 0))
		data->len--;
	while (!data->f_neg && i < data->width_len - data->len)
	{
		ft_putchar(' ', data);
		i++;
	}
	ft_putstr("0x", data);
	while (data->prec && j < data->prec_len - data->len + 2)
	{
		ft_putchar('0', data);
		j++;
	}
	if (data->p == 0 && data->prec == 1 &&
			(data->neg_star == 1 || data->prec_len == 0))
		;
	else
		ft_put_addr(data->p, data);
	while (data->f_neg && i < data->width_len - data->len)
	{
		ft_putchar(' ', data);
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
	data->neg_star = 0;
}

void	parsor_width(t_struct *data)
{
	data->width = 1;
	if (data->str[data->i] == '*')
	{
		data->width_len = va_arg(data->args, int);
		data->i++;
		if (data->width_len < 0)
		{
			data->width_len = -data->width_len;
			data->f_neg = 1;
			data->neg_star = 1;
		}
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
	if (data->str[data->i] == 'd' || data->str[data->i] == 'i' ||
			data->str[data->i] == 'u')
		hq_int(data);
	if (data->str[data->i] == 's' || data->str[data->i] == 'c' ||
			data->str[data->i] == '%')
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
			data.ret++;
			data.i++;
		}
	}
	va_end(data.args);
	return (data.ret);
}

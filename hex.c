/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 05:33:58 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/25 05:36:48 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

void	hq_hex2(t_struct *data, int i, int j)
{
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
	hq_hex2(data, i, j);
}

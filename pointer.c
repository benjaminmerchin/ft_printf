/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 05:33:07 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/25 05:33:41 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

void	hq_pointer2(t_struct *data, int i, int j)
{
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
	hq_pointer2(data, i, j);
}

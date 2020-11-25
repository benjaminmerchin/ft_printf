/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 05:34:55 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/25 05:35:19 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	hq_int3(t_struct *data, int i, int j, int k)
{
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

void	hq_int2(t_struct *data, int i, int j, int k)
{
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
	hq_int3(data, i, j, k);
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
		data->s = ft_itoa_unsigned(va_arg(data->args, unsigned int), data);
	else
		data->s = ft_itoa(va_arg(data->args, int), data);
	if (data->s == NULL)
		return ;
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
	hq_int2(data, i, j, k);
}

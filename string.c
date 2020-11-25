/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 05:35:48 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/25 05:58:47 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	shq_s_c2(t_struct *data, int i, int j)
{
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
	shq_s_c2(data, i, j);
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

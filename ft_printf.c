/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 05:30:50 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/25 05:31:30 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

void	parsor_flag(t_struct *data)
{
	while (data->str[data->i] == '0' || data->str[data->i] == '-')
	{
		if (data->str[data->i] == '0')
			data->f_zero = '0';
		else
			data->f_neg = 1;
		data->i++;
	}
}

void	parsor(t_struct *data)
{
	init_struct(data);
	data->i++;
	parsor_flag(data);
	if ((data->str[data->i] >= '1' && data->str[data->i] <= '9') ||
	data->str[data->i] == '*')
		parsor_width(data);
	if (data->str[data->i] == '.')
		parsor_prec(data);
	if (data->str[data->i] == 'd' || data->str[data->i] == 'i' ||
			data->str[data->i] == 'u')
		hq_int(data);
	else if (data->str[data->i] == 's' || data->str[data->i] == 'c' ||
			data->str[data->i] == '%')
		hq_s_c(data);
	else if (data->str[data->i] == 'x' || data->str[data->i] == 'X')
		hq_hex(data);
	else if (data->str[data->i] == 'p')
		hq_pointer(data);
	else if (data->str[data->i] == '\0')
		data->i--;
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

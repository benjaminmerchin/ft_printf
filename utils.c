/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 05:31:58 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/25 05:38:45 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

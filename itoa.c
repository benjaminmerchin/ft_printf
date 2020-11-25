/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 05:37:01 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/25 05:40:27 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

char	*ft_itoa(int n, t_struct *data)
{
	char		*str;
	int			i;
	int			sign;
	long int	nbr;

	(void)data;
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

void	ft_itoa_fill_unsigned(char *str, unsigned long nbr, unsigned int i)
{
	unsigned int temp;

	temp = nbr % 10;
	str[i - 1] = temp + '0';
	nbr /= 10;
	if (nbr > 0)
		ft_itoa_fill_unsigned(str, nbr, i - 1);
}

char	*ft_itoa_unsigned(unsigned int n, t_struct *data)
{
	char				*str;
	unsigned int		i;
	unsigned int		sign;
	unsigned long int	nbr;

	(void)data;
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
	ft_itoa_fill_unsigned(str + sign, nbr, ft_intlen(nbr));
	str[ft_intlen(nbr) + sign] = '\0';
	return (str);
}

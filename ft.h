/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 07:03:28 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/12 22:05:13 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct	s_struct
{
	va_list	args;
	int		ret;
	int		i;
	int		num;
	char	*s;
	char	*str;
	int		len;
	int		f_neg;
	int		f_zero;
	int		width;
	int		width_len;
	int		prec;
	int		prec_len;
}				t_struct;

#endif

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

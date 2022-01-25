/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:39:44 by Dykk Dessie       #+#    #+#             */
/*   Updated: 2021/12/10 16:37:01 by Dykk Dessie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
The ft_litob() function converts unsigned long px->v to text (safe for 64-bit
integers) with the base according to the given conversion specifier c.
*/
void	ft_litob(t_pft *px, char c)
{
	char			t[24];
	int				i;
	unsigned long	ul_val;
	t_bsp			bsp;

	i = sizeof (t);
	bsp = ft_getbase(c);
	ul_val = (unsigned long) px->li_val;
	if ((c == 'd' || c == 'i') && px->li_val < 0)
		ul_val = -ul_val;
	if (ul_val != 0 || px->prec != 0)
		t[--i] = bsp.digits[ul_val % bsp.base];
	px->li_val = ul_val / bsp.base;
	while (0 < px->li_val && 0 < i)
	{
		t[--i] = bsp.digits[px->li_val % bsp.base];
		px->li_val /= bsp.base;
	}
	px->len_sval = sizeof (t) - i;
	ft_memcpy(px->str_val, &t[i], px->len_sval);
	if (px->len_sval < px->prec)
		px->len_zer = px->prec - px->len_sval;
	i = px->width - px->len_zer - px->len_pref - px->len_sval;
	if (px->prec < 0 && (px->flags & (FMI | FZE)) == FZE && i > 0)
		px->len_zer += i;
}

/*
The ft_getbase() function receives conversion specifier c and returns
t_bsp struct with corresponding base value bsp.base and pointer on
characters set bsp.digits.
*/
t_bsp	ft_getbase(char c)
{
	t_bsp	bsp;

	if (c == 'X')
		bsp.digits = "0123456789ABCDEF";
	else
		bsp.digits = "0123456789abcdef";
	if (c == 'o')
		bsp.base = 8;
	else
	{
		if (c != 'x' && c != 'X')
			bsp.base = 10;
		else
			bsp.base = 16;
	}
	return (bsp);
}

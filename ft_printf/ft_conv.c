/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:38:31 by Dykk Dessie       #+#    #+#             */
/*   Updated: 2021/12/11 19:45:26 by Dykk Dessie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

/*
The ft_charconv() function converts a single character.
*/
void	ft_charconv(t_pft *px, va_list *pap)
{
	px->str_pref[px->len_pref++] = va_arg(*pap, int);
}

/*
The ft_dintconv() function converts a signed decimal integer.
*/
void	ft_dintconv(t_pft *px, va_list *pap, char c)
{
	px->li_val = va_arg(*pap, int);
	if (px->li_val < 0)
		px->str_pref[px->len_pref++] = '-';
	else if (px->flags & FPL)
		px->str_pref[px->len_pref++] = '+';
	else if (px->flags & FSP)
		px->str_pref[px->len_pref++] = ' ';
	px->str_val = &px->str_pref[px->len_pref];
	ft_litob(px, c);
}

/*
The ft_uintconv() function converts unsigned.
*/
void	ft_uintconv(t_pft *px, va_list *pap, char c)
{
	px->li_val = (unsigned int) va_arg(*pap, int);
	if (px->flags & FNO && px->li_val != 0)
	{
		px->str_pref[px->len_pref++] = '0';
		if (c == 'x' || c == 'X')
			px->str_pref[px->len_pref++] = c;
	}
	px->str_val = &px->str_pref[px->len_pref];
	ft_litob(px, c);
}

/*
The ft_strconv() function converts a string.
*/
void	ft_strconv(t_pft *px, va_list *pap)
{
	px->str_val = va_arg(*pap, char *);
	if (px->str_val)
	{
		px->len_sval = ft_strlen(px->str_val);
		if (px->prec >= 0 && px->prec < px->len_sval)
			px->len_sval = px->prec;
	}
	else
	{
		if (px->prec < 0 || px->prec >= 6)
		{
			px->len_sval += 6;
			px->str_val = "(null)";
		}
		else
		{
			px->str_val = NULL;
		}
	}
}

/*
The ft_ptrconv() function converts a pointer, hex long version
*/
void	ft_ptrconv(t_pft *px, va_list *pap)
{
	px->li_val = (long)va_arg(*pap, void *);
	if (px->li_val == 0)
		px->width = 1;
	px->str_pref[px->len_pref++] = '0';
	px->str_pref[px->len_pref++] = 'x';
	px->str_val = &px->str_pref[px->len_pref];
	ft_litob(px, 'x');
}

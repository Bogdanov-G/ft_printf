/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:24:06 by Dykk Dessie       #+#    #+#             */
/*   Updated: 2021/12/10 16:30:15 by Dykk Dessie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/*
The ft_specconv() function determinates which conversion function
should be used depend on the given specifier's value.
*/
void	ft_specconv(t_pft *px, va_list *pap)
{
	char	c;

	c = *px->fmt_tmp;
	px->len_sval = 0;
	px->len_pref = 0;
	px->len_zer = 0;
	if (c == 'c')
		ft_charconv(px, pap);
	else if (c == 'd' || c == 'i')
		ft_dintconv(px, pap, c);
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
		ft_uintconv(px, pap, c);
	else if (c == 's')
		ft_strconv(px, pap);
	else if (c == 'p')
		ft_ptrconv(px, pap);
	else if (c == '%')
	{
		px->str_pref[px->len_pref++] = '%';
		px->flags = 0;
		px->width = 0;
		px->prec = 0;
	}
	px->width -= px->len_pref + px->len_zer + px->len_sval;
}

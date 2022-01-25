/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsprec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:21:01 by Dykk Dessie       #+#    #+#             */
/*   Updated: 2021/12/10 16:37:09 by Dykk Dessie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/*
The ft_parsprec() function gets information about precision from
conversion specifier and packs it into _Pft struct.
*/
void	ft_parsprec(t_pft *px, va_list *pap)
{
	if (*px->fmt_tmp != '.')
		px->prec = -1;
	else if (*++px->fmt_tmp == '*')
	{
		px->prec = va_arg(*pap, int);
		++px->fmt_tmp;
	}
	else
	{
		px->prec = 0;
		while (ft_isdigit(*px->fmt_tmp))
			if (px->prec < WMAX)
				px->prec = px->prec * 10 + *px->fmt_tmp++ - '0';
	}
}

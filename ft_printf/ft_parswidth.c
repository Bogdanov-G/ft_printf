/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parswidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:15:05 by Dykk Dessie       #+#    #+#             */
/*   Updated: 2021/12/10 16:37:13 by Dykk Dessie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/*
The ft_parswidth() function gets information about field width from
conversion specifier and packs it into _Pft struct.
*/
void	ft_parswidth(t_pft *px, va_list *pap)
{
	if (*px->fmt_tmp == '*')
	{
		px->width = va_arg(*pap, int);
		if (px->width < 0)
		{
			px->width = -px->width;
			px->flags |= FMI;
		}
		++px->fmt_tmp;
	}
	else
	{
		px->width = 0;
		while (ft_isdigit(*px->fmt_tmp))
		{
			if (px->width < WMAX)
				px->width = px->width * 10 + *px->fmt_tmp++ - '0';
		}
	}
}

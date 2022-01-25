/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:48:38 by ddessie           #+#    #+#             */
/*   Updated: 2021/12/10 16:37:16 by Dykk Dessie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/*
The ft_printf() function produce output according to a format as original
printf(), exept it manages only:
 - conversions 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%';
 - flags '-', '0', '.', '#', ' ', '+'.
*/
int	ft_printf(const char *fmt, ...)
{
	int		ans;
	va_list	ap;

	va_start(ap, fmt);
	ans = ft_vprintf(fmt, &ap);
	va_end(ap);
	return (ans);
}

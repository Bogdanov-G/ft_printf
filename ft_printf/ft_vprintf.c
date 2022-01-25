/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:49:17 by ddessie           #+#    #+#             */
/*   Updated: 2021/12/12 12:08:35 by Dykk Dessie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_vprintf(const char *fmt, va_list *pap)
{
	t_pft	x;

	x.printed = 0;
	x.str_pref = malloc(sizeof(char) * 32);
	if (!x.str_pref)
		return (-1);
	while (1)
	{
		x.fmt_tmp = ft_strspec(fmt);
		writecnt(FD, fmt, x.fmt_tmp - fmt, &x.printed);
		if (*x.fmt_tmp == '\0')
		{
			ft_free(&x);
			return (x.printed);
		}
		ft_specpars(&x, pap);
		if (*x.fmt_tmp == '\0')
		{
			ft_free(&x);
			return (x.printed);
		}
		ft_specconv(&x, pap);
		ft_puter(&x);
		fmt = x.fmt_tmp + 1;
	}
}

void	ft_free(t_pft *px)
{
	if (px->str_pref)
		free(px->str_pref);
	else
		free(px->str_val);
}

void	ft_puter(t_pft *px)
{
	if (!(px->flags & FMI))
		writepad(FD, ' ', px->width, &px->printed);
	writecnt(FD, px->str_pref, px->len_pref, &px->printed);
	writepad(FD, '0', px->len_zer, &px->printed);
	writecnt(FD, px->str_val, px->len_sval, &px->printed);
	if (px->flags & FMI)
		writepad(FD, ' ', px->width, &px->printed);
}

void	writepad(int fd, const char c, int n, int *cnt)
{
	char		*buf;
	int			mult;

	mult = n / 32;
	n %= 32;
	if (c == ' ')
		buf = "                                ";
	else
		buf = "00000000000000000000000000000000";
	while (mult-- > 0)
		writecnt(fd, buf, 32, cnt);
	writecnt(fd, buf, n, cnt);
}

void	writecnt(int fd, const void *buf, int n, int *cnt)
{
	int		printed;

	printed = 0;
	if (n <= 0)
		return ;
	printed = write(fd, buf, n);
	if (printed > 0)
		*cnt += printed;
}

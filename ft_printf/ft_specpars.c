/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specpars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:11:29 by Dykk Dessie       #+#    #+#             */
/*   Updated: 2021/12/10 16:30:24 by Dykk Dessie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/*
The ft_specpars() function parses a conversion specifier and packs
information about flags, field width and precision into t_pft struct.
*/
void	ft_specpars(t_pft *px, va_list *pap)
{
	if (!px->fmt_tmp)
		return ;
	px->fmt_tmp++;
	ft_parsflag(px);
	ft_parswidth(px, pap);
	ft_parsprec(px, pap);
}

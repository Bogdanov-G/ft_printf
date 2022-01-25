/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:13:31 by Dykk Dessie       #+#    #+#             */
/*   Updated: 2021/12/10 16:37:05 by Dykk Dessie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
The ft_parsflag() function gets information about flags from conversion
specifier and packs it into _Pft struct.
*/
void	ft_parsflag(t_pft *px)
{
	const char			*flag;
	const char			char_flags[] = {" +-#0"};
	const unsigned int	bit_flags[] = {
		FSP, FPL, FMI, FNO, FZE, 0
	};

	px->flags = 0;
	flag = ft_strchr(char_flags, *px->fmt_tmp++);
	while (flag)
	{
		px->flags |= bit_flags[flag - char_flags];
		flag = ft_strchr(char_flags, *px->fmt_tmp++);
	}
	--px->fmt_tmp;
}

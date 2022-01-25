/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:09:45 by Dykk Dessie       #+#    #+#             */
/*   Updated: 2021/12/10 16:38:11 by Dykk Dessie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
The ft_strspec() function returns a pointer to the first occurrence of the
conversion specifier's character ('%') in the string s or a pointer to '\0'.
*/
const char	*ft_strspec(const char *s)
{
	while (*s)
	{
		if (*s++ == '%')
		{
			--s;
			break ;
		}
	}
	return (s);
}

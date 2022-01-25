/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:18:02 by Dykk Dessie       #+#    #+#             */
/*   Updated: 2021/12/10 16:31:21 by Dykk Dessie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
The ft_strchr() function returns a pointer to the first occurrence of the
character c in the string s.
*/
char	*ft_strchr(const char *s, int c)
{
	const char	cc = c;

	while (s && *s != cc)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

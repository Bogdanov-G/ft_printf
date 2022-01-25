/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:53:22 by Dykk Dessie       #+#    #+#             */
/*   Updated: 2021/12/12 12:08:35 by Dykk Dessie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>

/*
File descriptor using for write().
*/
# define FD 1

/*
Conversion cpecifier (space,+,-,#,0) are presented with following flags
*/
# define FSP 0x01
# define FPL 0x02
# define FMI 0x04
# define FNO 0x08
# define FZE 0x10

/* 
The max limit for field width and precission values.
*/
# define WMAX 999

/*
The pft is a structure into which ft_vprintf packs information about a
conversion specifier. Information filled by subordinate functions.
*/
typedef struct s_pft
{
	int				prec;
	int				width;
	unsigned int	flags;
	long			li_val;
	char			*str_val;
	int				len_sval;
	char			*str_pref;
	int				len_pref;
	int				len_zer;
	const char		*fmt_tmp;
	int				printed;
}	t_pft;

typedef struct s_bsp
{
	char	*digits;
	int		base;
}	t_bsp;

const char	*ft_strspec(const char *s);
void		ft_specpars(t_pft *px, va_list *pap);
void		ft_parsflag(t_pft *px);
void		ft_parswidth(t_pft *px, va_list *pap);
void		ft_parsprec(t_pft *px, va_list *pap);
int			ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
void		ft_specconv(t_pft *px, va_list *pap);
void		ft_charconv(t_pft *px, va_list *pap);
void		ft_dintconv(t_pft *px, va_list *pap, char c);
void		ft_uintconv(t_pft *px, va_list *pap, char c);
void		ft_strconv(t_pft *px, va_list *pap);
void		ft_ptrconv(t_pft *px, va_list *pap);
void		ft_litob(t_pft *px, char c);
t_bsp		ft_getbase(char c);
void		writecnt(int fd, const void *buf, int n, int *cnt);
void		writepad(int fd, const char c, int n, int *cnt);
void		ft_puter(t_pft *px);
void		ft_free(t_pft *px);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_vprintf(const char *fmt, va_list *pap);
size_t		ft_strlen(const char *s);
int			ft_printf(const char *fmt, ...);
#endif
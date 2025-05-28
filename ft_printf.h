/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:09:20 by Mal               #+#    #+#             */
/*   Updated: 2025/05/28 02:46:55 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:48:53 by Mal          #+#    #+#             */
/*   Updated: 2025/05/10 22:27:50 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define NULL_STR "(null)"
# define NIL_STR "(nil)"
# define PAD_LEFT 0
# define PAD_RIGHT 1
# define FALSE 0
# define TRUE 1

/* 
 *		flags:
 *		' ' --> provide extra space for a sign
 *		'0' --> pads value with zeros
 *		'#' --> pads hex with 0x or 0X 
 *		'+' --> forces sign usage on numbers (overrides space)
 *		'-' --> places padding on the right (overrides zero)
 *		
 *		important notes:
 *		- '#' always place 0x on the left, regardless of '-'
 *		
 *		
 */
typedef struct s_pdata
{
	int		space_for_sign;
	int		force_sign;
	int		pad_0x;
	char	zero_pad;
	int		padding_side;
	int		padding_length;
	int		len;
	int		early_break;
	int		precision;
	int		has_precision;
}	t_pdata;

t_pdata	*fl_init(void);

int		ft_printf(const char *format, ...);

int		matches(char c, char *any);
int		handle_padding(t_pdata *flags, int len, int side);

int		format_delegator(
			int index, va_list params, const char *format, t_pdata *flags);

int		print_char(int c, t_pdata *flags);
int		print_dec_int(int n, t_pdata *flags);
int		print_pointer(void *ptr, t_pdata *flags);
int		print_string(char *str, t_pdata *flags);
int		print_uint(unsigned int uint, t_pdata *flags);
int		print_hex(unsigned int hex, char hcase, t_pdata *flags);

char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	ft_putchar(int a);
void	ft_putstr(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
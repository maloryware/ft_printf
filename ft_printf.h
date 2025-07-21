/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:09:20 by Mal               #+#    #+#             */
/*   Updated: 2025/07/21 09:34:06 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "include/libft/libft.h"
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>


# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define NULL_STR "(null)"
# define NIL_PTR "(nil)"
# define PAD_LEFT 1
# define PAD_RIGHT 2
# define FALSE 0
# define TRUE 1

/*
 *		flags:
 *		' ' --> provide extra space for a sign
 *		'0' --> pads value with zeros
 *		'#' --> pads hex with 0x or 0X
 *		'+' --> forces sign usage on numbers (overrides space)
 *		'-' --> places padding on the right (overrides zero)
 *		'.' --> defines obligatory number of visible characters
 *			  		\--	!! ONLY OVERRIDES PADDING !!
 *
 *		important notes:
 *		- '#' always place 0x on the left, regardless of '-'
 *		- '.' defines exact amount of visible characters
 *				UNLESS the flagless value itself <= precision
 *		- negative zero-padded values must place sign first
 *		- 0x comes BEFORE zero pad, AFTER space pad
 *
 *		- fuck this project. seriously.
 *
 */
typedef struct s_format_data
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
}	t_format_data;

t_format_data	*fl_init(void);

int				ft_printf(const char *format, ...);

int				contains(char c, char *any);

int				format_delegator(
					int index, va_list params,
					const char *format, t_format_data *flags);

int				print_char(int c);
int				print_dec_int(int n);
int				print_pointer(void *ptr);
int				print_string(char *str);
int				print_uint(unsigned int uint);
int				print_hex(unsigned int hex, char hcase);
char			*ft_utoa(uint nb);

char			*get_case(char hcase);

#endif
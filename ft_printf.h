/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:09:20 by Mal               #+#    #+#             */
/*   Updated: 2025/07/24 13:46:26 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "sys/types.h"
# include <string.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define NULLSTR "(null)"
# define NULLPTR "(nil)"

int				ft_printf(const char *format, ...);
int				format_delegator(
					va_list params,
					const char *format);
int				print_char(int c);
int				print_dec_int(int n);
int				print_pointer(void *ptr);
int				print_string(char *str);
int				print_uint(uint num);
int				print_hex(uint hex, char *hex_case);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_delegator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:12:25 by Mal          #+#    #+#             */
/*   Updated: 2025/05/10 22:32:55 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

char	*get_case(char hcase)
{
	if (hcase == 'x')
		return (HEX_LOWER);
	if (hcase == 'X')
		return (HEX_UPPER);
	return (NULL);
}

int	format_delegator(
	va_list params,
	const char *format
)
{
	format++;
	if (*format == 'c')
		return (print_char(va_arg(params, int)));
	else if (*format == 's')
		return (print_string(va_arg(params, char *)));
	else if (*format == 'p')
		return (print_pointer(va_arg(params, void *)));
	else if (*format == 'd' || *format == 'i')
		return (print_dec_int(va_arg(params, int)));
	else if (*format == 'u')
		return (print_uint(va_arg(params, uint)));
	else if (*format == 'x' || *format == 'X')
		return (print_hex(va_arg(params, uint), get_case(*format)));
	else if (*format == '%')
		return (write(1, format, 1));
	return (0);
}

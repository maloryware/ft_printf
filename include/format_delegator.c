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

#include "../ft_printf.h"

int	format_delegator(
	int pos,
	va_list params,
	const char *format,
	t_format_data *f
)
{
	pos++;
	if (format[pos] == 'c')
		f->len += print_char(va_arg(params, int), f);
	else if (format[pos] == 's')
		f->len += print_string(va_arg(params, char *), f);
	else if (format[pos] == 'p')
		f->len += print_pointer(va_arg(params, void *), f);
	else if (format[pos] == 'd' || format[pos] == 'i')
		f->len += print_dec_int(va_arg(params, int), f);
	else if (format[pos] == 'u')
		f->len += print_uint(va_arg(params, unsigned int), f);
	else if (format[pos] == 'x' || format[pos] == 'X')
		f->len += print_hex(va_arg(params, unsigned int), format[pos], f);
	else if (format[pos] == '%')
		write(1, "%%", (f->len++) * 0 + 1);
	return (pos);
}



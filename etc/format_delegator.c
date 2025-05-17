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
#include <stdlib.h>

static void	set_padding_length(t_pdata *f, char *tofree)
{
	f->padding_length = atoi(tofree);
	free(tofree);
}

int	format_delegator(
	int i,
	va_list params,
	const char *format,
	t_pdata *f
)
{
	int	len;

	len = 0;
	i++;
	i = handle_flags(i++, format, f);
	while (matches(format[i + len], "0123456789"))
		len++;
	set_padding_length(f, ft_substr(format, i, len));
	i += len;
	if (format[i] == 'c')
		f->len += print_char(va_arg(params, int), f);
	else if (format[i] == 's')
		f->len += print_string(va_arg(params, char *), f);
	else if (format[i] == 'p')
		f->len += print_pointer(va_arg(params, void *), f);
	else if (format[i] == 'd' || format[i] == 'i')
		f->len += print_dec_int(va_arg(params, int), f);
	else if (format[i] == 'u')
		f->len += print_uint(va_arg(params, unsigned int), f);
	else if (format[i] == 'x' || format[i] == 'X')
		f->len += print_hex(va_arg(params, unsigned int), format[i], f);
	else if (format[i] == '%')
		write(1, "%%", (f->len++) * 0 + 1);
	return (i);
}

int	handle_flags(
	int pos,
	const char *format,
	t_pdata *f
)
{
	while (matches(format[pos], "#0-+ ."))
	{
		f->pad_0x = (format[pos] == '#' || f->pad_0x);
		f->padding_side = (format[pos] == '-' || f->padding_side);
		f->force_sign = (format[pos] == '+' || f->force_sign);
		f->space_for_sign = ((format[pos] == ' ' || f->space_for_sign)
				&& !f->force_sign);
		f->zero_pad = ((format[pos] == '0' || f->zero_pad)
				&& !f->padding_side);
		pos++;
	}
	return (pos);
}

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

static int	handle_flags(
				int pos,
				const char *format,
				t_pdata *f);

static int	set_padding_length(t_pdata *f, char *format, int pos)
{
	int		i;
	char	*tmp;

	i = 0;
	while (matches(format[pos + i], "0123456789"))
		i++;
	tmp = ft_substr(format, pos, i);
	f->padding_length = atoi(tmp);
	pos += i;
	free(tmp);
	return (pos);
}

static int	set_precision_length(t_pdata *f, char *format, int pos)
{
	int		i;
	char	*tmp;

	i = 0;
	while (matches(format[pos + i], "0123456789"))
		i++;
	tmp = ft_substr(format, pos, i);
	f->precision = atoi(tmp);
	pos += i;
	free(tmp);
	return (pos);
}

int	format_delegator(
	int i,
	va_list params,
	const char *format,
	t_pdata *f
)
{
	i++;
	i = handle_flags(i++, format, f);
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

static int	handle_flags(
				int pos,
				const char *format,
				t_pdata *f)
{
	while (matches(format[pos], "#0-+ .123456789"))
	{
		f->pad_0x = (format[pos] == '#' || f->pad_0x);
		f->padding_side = (format[pos] == '-' || f->padding_side);
		f->force_sign = (format[pos] == '+' || f->force_sign);
		f->space_for_sign = ((format[pos] == ' ' || f->space_for_sign)
				&& !f->force_sign);
		f->zero_pad = ((format[pos] == '0' || f->zero_pad)
				&& !f->padding_side);
		f->has_precision = ((format[pos] == '.' || f->has_precision));
		if (matches(format[pos], "123456789"))
			pos = set_padding_length(f, (char *) format, pos) - 1;
		pos++;
		if (format[pos - 1] == '.')
			pos = set_precision_length(f, (char *) format, pos);
	}
	return (pos);
}

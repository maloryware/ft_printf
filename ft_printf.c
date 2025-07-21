/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:48:49 by Mal               #+#    #+#             */
/*   Updated: 2025/07/07 13:03:58 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format_data	*fl_init(void)
{
	t_format_data		*data;

	data = malloc(sizeof(t_format_data));
	data->pad_0x = FALSE;
	data->zero_pad = FALSE;
	data->padding_side = 0;
	data->padding_length = 0;
	data->space_for_sign = FALSE;
	data->force_sign = FALSE;
	data->len = 0;
	data->precision = FALSE;
	data->has_precision = FALSE;
	return (data);
}

void	reset_data(t_format_data *data)
{
	data->pad_0x = FALSE;
	data->zero_pad = FALSE;
	data->padding_side = 0;
	data->padding_length = 0;
	data->space_for_sign = FALSE;
	data->force_sign = FALSE;
	data->precision = FALSE;
	data->has_precision = FALSE;
}

// TODO: see also: printf manpage 3

int	ft_printf(const char *format, ...)
{
	t_format_data			*f;
	int						index;
	int						len;
	va_list					params;

	if (!format)
		return (-1);
	f = fl_init();
	index = 0;
	va_start(params, format);
	while (format[index])
	{
		if (format[index] == '%')
			index = format_delegator(index, params, format, f);
		else
		{
			write(1, &format[index], 1);
			f->len++;
			reset_data(f);
		}
		index++;
	}
	len = f->len;
	free(f);
	return (len);
}

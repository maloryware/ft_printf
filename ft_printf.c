/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:48:49 by Mal          #+#    #+#             */
/*   Updated: 2025/05/10 22:36:24 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pdata	*fl_init(void)
{
	t_pdata		*data;

	data = malloc(sizeof(t_pdata));
	data->pad_0x = FALSE;
	data->zero_pad = FALSE;
	data->padding_side = PAD_LEFT;
	data->padding_length = 0;
	data->space_for_sign = FALSE;
	data->force_sign = FALSE;
	data->len = 0;
	return (data);
}

void	reset_pdata(t_pdata *data)
{
	data->pad_0x = FALSE;
	data->zero_pad = FALSE;
	data->padding_side = PAD_LEFT;
	data->padding_length = 0;
	data->space_for_sign = FALSE;
	data->force_sign = FALSE;
}

// TODO: see also: printf manpage 3

int	ft_printf(const char *format, ...)
{
	t_pdata			*f;
	int				index;
	int				len;
	va_list			params;

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
		}
		reset_pdata(f);
		index++;
	}
	len = f->len;
	free(f);
	return (len);
}

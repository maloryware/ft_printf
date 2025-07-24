/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:48:49 by Mal               #+#    #+#             */
/*   Updated: 2025/07/24 13:46:51 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int				len;
	va_list			params;

	if (!format)
		return (-1);
	va_start(params, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && *format + 1)
		{
			len += format_delegator(params, format);
			format++;
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(params);
	return (len);
}

/* int main()
{
	#include <stdio.h>

	ft_printf("Test: %d, %c, %s, %x\n", 12, 'L', "test", 0x1337);
	printf("Test: %d, %c, %s, %x\n", 12, 'L', "test", 0x1337);
} */
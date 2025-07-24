/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:44:11 by Mal          #+#    #+#             */
/*   Updated: 2025/05/10 22:29:39 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

static int	print_hex_ptr(unsigned long hex)
{
	int		len;
	char	out;

	len = 0;
	if (hex >= 16)
		len += print_hex_ptr(hex / 16);
	out = HEX_LOWER[hex % 16];
	len += write(1, &out, 1);
	return (len);
}

int	print_pointer(void *ptr)
{
	int			len;
	ulong		pointer;

	len = 0;
	pointer = (ulong) ptr;
	if (!pointer)
		return (write(1, NULLPTR, 5));
	len += write(1, "0x", 2);
	len += print_hex_ptr(pointer);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:49:28 by Mal          #+#    #+#             */
/*   Updated: 2025/05/10 21:19:02 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_hex(uint hex, char *hex_case)
{
	int		len;
	char	out;

	len = 0;
	if (hex >= 16)
		len += print_hex(hex / 16, hex_case);
	out = hex_case[hex % 16];
	len += write(1, &out, 1);
	return (len);
}

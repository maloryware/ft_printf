/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 09:36:55 by Mal               #+#    #+#             */
/*   Updated: 2025/07/24 13:30:13 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_uint(uint num)
{
	uint	len;
	char	out;

	len = 0;
	if (num >= 10)
		len += print_uint(num / 10);
	out = num % 10 + '0';
	len += write(1, &out, 1);
	return (len);
}

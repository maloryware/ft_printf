/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 09:36:55 by Mal               #+#    #+#             */
/*   Updated: 2025/07/21 09:41:26 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* unit tested */
#include "../../ft_printf.h"

int	print_uint(uint unsigned_n)
{
	uint	len;
	char	*number;

	number = ft_utoa(unsigned_n);
	len = ft_strlen(number);
	write(1, number, len);
	return (len);
}

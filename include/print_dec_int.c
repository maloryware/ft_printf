/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        	  */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:44:08 by Mal          #+#    #+#             	  */
/*   Updated: 2025/05/10 21:58:48 by Mal         ###   ########.fr       	  */
/*                                                                            */
/* ************************************************************************** */

/* unit tested */
#include "../ft_printf.h"

int	print_dec_int(int n)
{
	long	decimal;
	int		len;
	char	number;

	len = 0;
	decimal = n;
	if (decimal < 0)
	{
		len += write(1, "-", 1);
		decimal = -decimal;
	}
	if (decimal >= 10)
		len += print_dec_int(decimal / 10);
	number = (decimal % 10) + '0';
	len += write(1, &number, 1);
	return (len);
}

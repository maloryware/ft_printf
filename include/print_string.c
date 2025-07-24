/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:46:30 by Mal               #+#    #+#             */
/*   Updated: 2025/07/24 13:11:12 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int	print_string(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (write(1, NULLSTR, 6));
	if (!str)
		str = "(null)";
	while (str[len])
		len += write(1, (str + len), 1);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:07:38 by Mal               #+#    #+#             */
/*   Updated: 2025/07/07 13:07:45 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	contains(char c, char *any)
{
	int	x;

	x = ft_strlen(any);
	while (x--)
		if (c == any[x])
			return (1);
	return (0);
}

char	*get_case(char hcase)
{
	if (hcase == 'x')
		return (HEX_LOWER);
	if (hcase == 'X')
		return (HEX_UPPER);
	return (NULL);
}


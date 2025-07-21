/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 06:50:27 by Mal               #+#    #+#             */
/*   Updated: 2025/07/21 09:41:38 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_printf.h"

static int	get_ulen(uint n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*mini_utoc(uint nb, int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (nb > 0)
	{
		str[--len] = '0' + (nb % 10);
		nb /= 10;
	}
	return (str);
}

char	*ft_utoa(uint nb)
{
	char	*str;
	int		len;

	if (nb == 0)
	{
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	len = get_ulen(nb);
	str = mini_utoc(nb, len);
	return (str);
}

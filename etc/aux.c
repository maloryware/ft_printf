/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:53:33 by Mal          #+#    #+#             */
/*   Updated: 2025/05/10 21:52:16 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	matches(char c, char *any)
{
	int	x;

	x = ft_strlen(any);
	while (x--)
		if (c == any[x])
			return (1);
	return (0);
}

int	handle_padding(t_pdata *flags, int len, int side)
{
	char	*pad;
	int		pad_len;

	if (side != flags->padding_side
		|| flags->padding_length <= len)
		return (len);
	pad = " ";
	if (flags->zero_pad)
		pad = "0";
	pad_len = flags->padding_length - len;
	len = flags->padding_length;
	while (pad_len--)
		write(1, pad, 1);
	return (len);
}

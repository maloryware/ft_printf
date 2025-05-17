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

#include "../../ft_printf.h"

static char	*htol(unsigned long long addr)
{
	char			*out;
	int				i;
	unsigned long	addr_ref;

	i = 0;
	addr_ref = addr;
	while (addr_ref)
	{
		addr_ref /= 16;
		i++;
	}
	i += 1;
	out = ft_calloc(i, sizeof(char));
	out[0] = '0';
	out[1] = 'x';
	while (i - 1)
	{
		out[i--] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	return (out);
}

int	print_pointer(void *ptr, t_pdata *flags)
{
	int		len;
	char	*out;

	out = htol((unsigned long long) ptr);
	len = ft_strlen(out);
	len = handle_padding(flags, len, PAD_LEFT);
	ft_putstr(out);
	len = handle_padding(flags, len, PAD_RIGHT);
	return (len);
}

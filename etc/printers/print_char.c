/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:47:38 by Mal               #+#    #+#             */
/*   Updated: 2025/05/17 02:09:46 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	print_char(int c, t_pdata *f)
{
	int		len;
	char	ch;

	ch = (unsigned char) c;
	len = 1;
	f->zero_pad = FALSE;
	len = handle_padding(f, len, PAD_LEFT);
	write(1, &ch, 1);
	len = handle_padding(f, len, PAD_RIGHT);
	return (len);
}

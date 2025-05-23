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

#include "../../ft_printf.h"

static int	handle_plus_space(int n, t_pdata *flags, int side)
{
	if (!(flags->padding_side == side))
		return (0);
	if (n >= 0 && flags->force_sign)
		ft_putchar('+');
	if (n >= 0 && flags->space_for_sign)
		ft_putchar(' ');
	return (1);
}

static void	putchar_looper(int a, int count)
{
	unsigned char	c;

	c = (unsigned char) a;
	while (count--)
		write(1, &c, 1);
}

static int	extra_flags(int len, t_pdata *flags, int n, int phase)
{
	len += handle_plus_space(n, flags, phase);
	if (phase == 1 && flags->padding_side == PAD_RIGHT)
		putchar_looper(0, flags->precision);
	if (phase == 2 && flags->padding_side == PAD_LEFT)
		putchar_looper(0, flags->precision);
	return (len);
}

int	print_dec_int(int n, t_pdata *flags)
{
	char	*out;
	int		len;

	out = ft_itoa(n);
	len = extra_flags(ft_strlen(out), flags, n, 0);
	len = handle_padding(flags, len, PAD_LEFT);
	len = extra_flags(len, flags, n, 1);
	write(1, out, ft_strlen(out));
	len = handle_padding(flags, len, PAD_RIGHT);
	len = extra_flags(len, flags, n, 2);
	free(out);
	return (len);
}

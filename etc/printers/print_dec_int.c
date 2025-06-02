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
	return (flags->force_sign | flags->space_for_sign);
}

static int	extra_flags(int len, t_pdata *flags, unsigned int n, int phase)
{
	int	count;
	int	len_tmp;

	len_tmp = len;
	if (phase == 1)
	{
		count = flags->precision;
		while (count-- > 0)
		{
			write(1, "0", 1);
			len_tmp++;
		}
	}
	len += handle_plus_space(n, flags, phase);
	return (len);
}

int	print_dec_int(int n, t_pdata *flags)
{
	char	*out;
	int		len;
	int		original_length;

	out = ft_itoa(n);
	original_length = ft_strlen(out);
	if (flags-> has_precision)
		flags->precision -= original_length;
	len = extra_flags(original_length, flags, n, 0);
	len = handle_padding(flags, len + flags->precision, PAD_LEFT);
	len = extra_flags(len, flags, n, 1);
	write(1, out, original_length);
	len = handle_padding(flags, len, PAD_RIGHT);
	free(out);
	return (len);
}

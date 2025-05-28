/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:47:29 by Mal          #+#    #+#             */
/*   Updated: 2025/05/10 21:25:46 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static size_t	digit_count_u(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*utoa(unsigned int n)
{
	size_t			digits;
	size_t			i;
	char			*str;
	unsigned int	num;

	num = n;
	digits = digit_count_u(n);
	str = (char *)malloc(digits + 1);
	if (!str)
		return (NULL);
	str[digits] = '\0';
	i = digits - 1;
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

static int	handle_plus_space_u(int n, t_pdata *flags, int side)
{
	if (!(flags->padding_side == side))
		return (0);
	if (n >= 0 && flags->force_sign)
		ft_putchar('+');
	if (n >= 0 && flags->space_for_sign)
		ft_putchar(' ');
	return (flags->force_sign | flags->space_for_sign);
}

static int	extra_flags_u(int len, t_pdata *flags, unsigned int n, int phase)
{
	int	count;

	len += handle_plus_space_u(n, flags, phase);
	if (phase == 1)
	{
		count = flags->precision;
		while (count-- > 0)
			write(1, "0", 1);
	}
	return (len);
}

int	print_uint(unsigned int n, t_pdata *flags)
{
	char	*out;
	int		len;
	int		original_length;
	int		original_precision;

	out = utoa(n);
	original_length = ft_strlen(out);
	original_precision = flags->precision;
	flags->precision -= original_length;
	len = extra_flags_u(original_length, flags, n, 0);
	len = handle_padding(flags, len + original_precision, PAD_LEFT);
	write(1, out, ft_strlen(out));
	len = extra_flags_u(len, flags, n, 1);
	len = handle_padding(flags, len, PAD_RIGHT);
	free(out);
	return (len);
}

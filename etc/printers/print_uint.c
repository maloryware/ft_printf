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

static size_t	digit_count_again(int n)
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
	digits = digit_count_again(n);
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

int	print_uint(unsigned int uint, t_pdata *flags)
{
	char	*out;
	int		len;

	if (flags->has_precision)
		flags->padding_length = flags->precision;
	out = utoa(uint);
	len = ft_strlen(out);
	if (flags->force_sign || flags->space_for_sign)
		len++;
	len = handle_padding(flags, len, PAD_LEFT);
	if (flags->space_for_sign)
		ft_putchar(' ');
	if (flags->force_sign)
		ft_putchar('+');
	write(1, out, ft_strlen(out));
	len = handle_padding(flags, len, PAD_RIGHT);
	free(out);
	return (len);
}

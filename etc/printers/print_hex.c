/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:49:28 by Mal          #+#    #+#             */
/*   Updated: 2025/05/10 21:19:02 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*get_case(char hcase)
{
	if (hcase == 'x')
		return (HEX_LOWER);
	if (hcase == 'X')
		return (HEX_UPPER);
	return (NULL);
}

static char	*get_padding_case(char hcase)
{
	if (hcase == 'x')
		return ("0x");
	if (hcase == 'X')
		return ("0X");
	return (NULL);
}

static char	*reverse_hex(char *hex, int len)
{
	int		i;
	char	*out;

	i = 0;
	out = ft_calloc(len + 1, sizeof(char));
	while (len-- >= 0)
		out[len] = hex[i++];
	free(hex);
	hex = NULL;
	return (out);
}

static char	*ft_atoh(int hex, const char *set)
{
	char	*last;
	int		i;
	int		hex_tmp;

	hex_tmp = hex;
	i = 0;
	while (hex_tmp)
	{
		hex_tmp /= 16;
		i++;
	}
	last = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (hex)
	{
		last[i] = set[hex % 16];
		i++;
		hex /= 16;
	}
	last = reverse_hex(last, i);
	return (last);
}

int	print_hex(unsigned int hex, char hcase, t_pdata *f)
{
	int			len;
	char		*out;
	const char	*set;

	set = get_case(hcase);
	out = ft_atoh(hex, set);
	if (!out)
		ft_strlcpy(out, "0", 1);
	len = ft_strlen(out);
	len = handle_padding(f, len, PAD_LEFT);
	if (f->pad_0x)
		write(1, get_padding_case(hcase), 2);
	if (f->pad_0x)
		len += 2;
	len = handle_padding(f, len, PAD_RIGHT);
	ft_putstr(out);
	free(out);
	return (len);
}

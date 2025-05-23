/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:47:26 by Mal          #+#    #+#             */
/*   Updated: 2025/05/10 21:25:30 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	print_string(char *str, t_pdata *flags)
{
	int	len;
	int	limit;

	limit = flags->has_precision * flags->precision;
	if (limit)
		str = ft_substr(str, 0, limit);
	len = ft_strlen(str);
	if (!flags->zero_pad)
		len = handle_padding(flags, len, PAD_LEFT);
	ft_putstr(str);
	if (!flags->zero_pad)
		len = handle_padding(flags, len, PAD_RIGHT);
	return (len);
}

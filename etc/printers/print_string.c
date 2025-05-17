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

	len = handle_padding(flags, ft_strlen(str), PAD_LEFT);
	ft_putstr(str);
	len = handle_padding(flags, len, PAD_RIGHT);
	return (len);
}

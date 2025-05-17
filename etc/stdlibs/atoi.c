/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:02:44 by Mal          #+#    #+#             */
/*   Updated: 2025/05/09 23:56:41 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_isspace(int n)
{
	return ((n >= 9 && n <= 13) || n == 32);
}

static int	checkneg(int n)
{
	if (n == '-')
		return (-1);
	return (1);
}

static int	epow(int n, int pow)
{
	while (pow > 0)
	{
		n *= 10;
		pow--;
	}
	return (n);
}

static int	ft_isdigit(int i)
{
	return ((i >= 48 && i <= 57));
}

int	atoi(const char *nptr)
{
	int	i;
	int	out;
	int	neg;
	int	count;

	out = 0;
	i = 0;
	count = 0;
	neg = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		neg *= checkneg(nptr[i++]);
	while (ft_isdigit(nptr[i + count]))
		count++;
	while (ft_isdigit(nptr[i]))
		out += epow(nptr[i++] - 48, --count);
	return (out * neg);
}

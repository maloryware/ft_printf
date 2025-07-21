/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:56:46 by Mal          #+#    #+#             */
/*   Updated: 2025/05/06 19:13:40 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	out;

	if (!fd)
		return ;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n == -2147483648)
		return ;
	if (n < 0)
		write(fd, "-", 1);
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	out = (n % 10) + '0';
	write(fd, &out, 1);
}

/* int main()
{
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
	ft_putnbr_fd(0, 1);
	printf("\n");
	ft_putnbr_fd(-1, 1);
	printf("\n");
	ft_putnbr_fd(1234567, 1);
	printf("\n");
} */
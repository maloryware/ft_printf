/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:01:06 by Mal          #+#    #+#             */
/*   Updated: 2025/05/06 19:11:30 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	str = (unsigned char *) s;
	chr = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}

/* int	main()
{
	void	*ptr = memchr("you will find Z in this string!", 'Z', 23);
	void	*ptr2 = memchr("you won't find Z in this string!", 'Z', 6);
	void	*ptr3 = memchr(0, 'Z', 6);
	return (0);
}
 */
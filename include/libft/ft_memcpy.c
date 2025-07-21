/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:04:56 by Mal          #+#    #+#             */
/*   Updated: 2025/05/03 18:52:32 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	i = 0;
	s = (const char *)src;
	d = (char *)dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/* int main()
{
	char *ptr1 = "test123";
	char *ptr2 = malloc(7);
	char *ptr1_local = "test123";
	char *ptr2_local = malloc(7);
	memcpy(ptr2, ptr1, 4);
	ft_memcpy(ptr2_local, ptr1_local, 4);
	return (0);
} */
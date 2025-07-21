/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:53:59 by Mal          #+#    #+#             */
/*   Updated: 2025/05/03 18:58:04 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dst_ref;
	unsigned char		*src_ref;
	size_t				i;

	dst_ref = (unsigned char *) dest;
	src_ref = (unsigned char *) src;
	if (dst_ref > src_ref && dst_ref < src_ref + len)
	{
		while (len--)
			dst_ref[len] = src_ref[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst_ref[i] = src_ref[i];
			i++;
		}
	}
	return (dest);
}

/* int main()
{
	char *ptr1 = "test56789ABCDEFXYZ123123123";
	char *ptr2 = malloc(14 * sizeof(char));
	char *ptr1_local = ptr1;
	char *ptr2_local = malloc(14 * sizeof(char));
	ft_memmove(ptr2_local, ptr1_local, 0);
	memmove(ptr2, ptr1, 0);
	return (0);
} */
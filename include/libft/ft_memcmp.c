/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:31:36 by Mal          #+#    #+#             */
/*   Updated: 2025/05/06 19:13:57 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

/* int main()
{
	int test1 = memcmp("success: string 1", "success: string 2", 28);
	int test1_local = ft_memcmp("success: string 1", "success: string 2", 28);
	int test2 = memcmp("fail: string 1", "fail: string 2", 4);
	int test2_local = ft_memcmp("fail: string 1", "fail: string 2", 4);
	return (1);
} */

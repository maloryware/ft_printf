/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:41:54 by Mal          #+#    #+#             */
/*   Updated: 2025/04/30 10:22:37 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *) s;
	while (i < n)
		ptr[i++] = (char) c;
	return (s);
}

/* int main()
{
	char	*ptr;
	ptr = malloc(16);
	ft_memset(ptr, 'A', 8);
	return (0);
} */
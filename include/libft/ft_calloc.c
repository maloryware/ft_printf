/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:19:44 by Mal          #+#    #+#             */
/*   Updated: 2025/05/06 19:19:56 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	max_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	max_size = nmemb * size;
	if (size != 0 && nmemb != (max_size / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* int	main()
{
	char *ptr1 = calloc(0, 0);
	char *ptr2 = ft_calloc(14, 2);
	char *ptr2 = ft_calloc(255, 255);
} */
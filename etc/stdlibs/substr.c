/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:43:04 by Mal          #+#    #+#             */
/*   Updated: 2025/05/09 23:45:00 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

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
	ft_memset(ptr, 0, nmemb);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	max_len;
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	max_len = ft_strlen(s);
	if (start >= max_len)
		return (ft_strdup(""));
	if (len > max_len - start)
		len = max_len - start;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

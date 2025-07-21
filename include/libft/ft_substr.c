/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:18:56 by Mal          #+#    #+#             */
/*   Updated: 2025/05/06 19:41:21 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* int main()
{
	char haystack[] = "you must hide the needle and all that follows!";
	printf("%s\n", ft_substr(haystack, 0, 14));
	printf("%s\n", ft_substr(haystack, 14, 47));
} */
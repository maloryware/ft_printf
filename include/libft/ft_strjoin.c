/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:00:27 by Mal          #+#    #+#             */
/*   Updated: 2025/05/06 19:24:51 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*out;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	out = (char *) ft_calloc(s1_size + s2_size + 1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		out[j++] = s1[i++];
	i = 0;
	while (s2[i])
		out[j++] = s2[i++];
	out[j] = '\0';
	return (out);
}

/* int main()
{
	printf("%s\n", ft_strjoin("fetch me ", "their souls!"));
	printf("%s\n", ft_strjoin("fetch me ", ""));
	printf("%s\n", ft_strjoin("", "saaaaaaaaaa"));
	printf("%s\n", ft_strjoin(NULL, "hii"));
	printf("%s\n", ft_strjoin("hellooo", NULL));
	// printf("%s\n", ft_strjoin(NULL, NULL));
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:10:01 by Mal          #+#    #+#             */
/*   Updated: 2025/05/06 19:40:34 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_gtr(char const *s, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		i++;
	}
	return (i);
}

static int	end_gtr(char const *s, char const *set, int end)
{
	int	i;
	int	j;

	i = end;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*out;

	if (!s1 || !set)
		return (NULL);
	start = start_gtr(s1, set);
	end = end_gtr(s1, set, ft_strlen(s1) - 1);
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1 + start, len + 1);
	return (out);
}

/* int main(void)
{
		const char str[] = "AABRACADABRAA";
		printf("%s\n", ft_strtrim(str, "A"));
		printf("%s\n", ft_strtrim(str, "x"));
		printf("%s\n", ft_strtrim(str, "ABR"));
		printf("%s\n", ft_strtrim(str, "DRABC"));
		printf("%s\n", ft_strtrim(NULL, NULL));
		return (0);
} */
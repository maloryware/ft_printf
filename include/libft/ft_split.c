/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:46:54 by Mal          #+#    #+#             */
/*   Updated: 2025/05/06 19:31:14 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			cnt++;
		i++;
	}
	return (cnt);
}

static char	*word_to_field(char const *s, int start, int end)
{
	int		i;
	char	*field;

	i = 0;
	field = malloc(sizeof(char) * (end - start + 1));
	if (!field)
		return (NULL);
	while (start < end)
	{
		field[i] = s[start];
		i++;
		start++;
	}
	field[i] = '\0';
	return (field);
}

static void	*free_all(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	place_words(char **out, const char *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			out[j] = word_to_field(s, start, i);
			if (!out[j])
				return (free_all(out, j), 0);
			j++;
		}
	}
	out[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**out;

	if (!s)
		return (ft_calloc(sizeof(char *), 1));
	out = ft_calloc(sizeof(char *), (count_words(s, c) + 1));
	if (!out)
		return (NULL);
	if (!place_words(out, s, c))
		return (NULL);
	return (out);
}

/* int main()
{
	ft_split("Hello! My name is Mal! How are you? :)", ' ');
	return (0);
}
 */
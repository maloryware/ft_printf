/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:34:25 by Mal               #+#    #+#             */
/*   Updated: 2025/07/21 06:15:06 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(const char *s, int b)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (b == '\0')
		return ((char *)s + ft_gnl_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)b)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*full_line(char *full_line, char *file_str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = -1;
	while (file_str[i] != '\0' && file_str[i - 1] != '\n')
		i++;
	temp = malloc(i + 1);
	if (!temp)
		return (NULL);
	while (++j < i)
		temp[j] = file_str[j];
	temp[j] = '\0';
	j = 0;
	while (file_str[i] != '\0')
		file_str[j++] = file_str[i++];
	file_str[j] = '\0';
	full_line = ft_gnl_strjoin(full_line, temp);
	free(temp);
	return (full_line);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joined;

	j = 0;
	i = 0;
	joined = malloc(ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			joined[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != '\0')
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	free(s1);
	return (joined);
}

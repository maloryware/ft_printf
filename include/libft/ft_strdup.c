/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:40:13 by Mal          #+#    #+#             */
/*   Updated: 2025/05/06 19:40:55 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*out;
	int		i;
	int		len;

	len = 0;
	while (s[len])
		len++;
	out = (char *) malloc(sizeof(char) * (len + 1));
	if (out == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

/* int main()
{
	char *str = "this string should be fully duplicated!";
	char *str1 = ft_strdup(str);
	return (0);
} */
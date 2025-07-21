/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:46:33 by Mal          #+#    #+#             */
/*   Updated: 2025/05/06 19:15:01 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	char_ref;

	i = 0;
	char_ref = (char) c;
	while (s[i])
	{
		if (s[i] == char_ref)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == '\0' && char_ref == '\0')
		return ((char *) &s[i]);
	return (NULL);
}

/* int main()
{
	printf("%s\n", ft_strchr("will locate the first 'o'", 'o'));
	printf("%s\n", ft_strchr("provides pointer to the terminator", '\0'));
	// printf("%s\n", ft_strchr("the pursued letter is absent", 'o'));
	// printf("%s\n", ft_strchr(NULL, 'n'));
	return (0);
}
 */
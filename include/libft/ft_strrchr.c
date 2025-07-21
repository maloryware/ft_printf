/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:51:04 by Mal          #+#    #+#             */
/*   Updated: 2025/05/06 19:19:03 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	c_ref;

	c_ref = (char) c;
	ptr = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c_ref)
			ptr = (char *)&s[i];
		i++;
	}
	if (s[i] == c_ref)
		ptr = (char *)&s[i];
	return (ptr);
}

/* int main()
{
	printf("%s\n", ft_strrchr("provides pointer to the terminator", '\0'));
	printf("%s\n", ft_strrchr("will locate the last 'o'", 'o'));
	// printf("%s\n", ft_strrchr("the pursued letter is absent", 'o'));
	// printf("%s\n", ft_strrchr(NULL, 'n'));
	return (0);
} */
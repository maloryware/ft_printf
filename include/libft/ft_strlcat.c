/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:34:38 by Mal          #+#    #+#             */
/*   Updated: 2025/05/04 19:51:12 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * appends `src` to `dst`, null terminating the result
 *
 * the final full buffer size (`size`) is taken so as to
 * ensure that 
 * [strlen(`src`) + strlen(`dest`) + 1 < `size`]
 *
 * if [`size` < strlen(`src`) + strlen(`dest`)], 
 * only appends enough characters of `src` to guarantee
 * [strlen(`src`) + strlen(`dest`) < `size`]
 * **and the string will not be nul-terminated**
 */

#include "libft.h"
/* #include "ft_strlen.c" */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len == size)
		return (size + src_len);
	i = 0;
	while (src[i] && size > (dst_len + i + 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/* int main()
{
	char *dst = malloc(128);
	for (int i = 3; i >= 0; i--)
		dst[i] = 'X';
	ft_strlcat(dst, "test", 8);
	ft_strlcat(dst, "test", 12);
	ft_strlcat(dst, "test", 16);
	return (0);
} */
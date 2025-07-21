/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:34:38 by Mal               #+#    #+#             */
/*   Updated: 2025/05/23 00:11:48 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* #include "get_next_line_utils.c" */

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*out;
	int			i;

	out = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (!*buf)
		{
			i = read(fd, buf, BUFFER_SIZE);
			if (i <= 0)
				break ;
			buf[i] = '\0';
		}
		if (ft_strchr(buf, '\n'))
			return (full_line(out, buf));
		out = ft_strjoin(out, buf);
		*buf = '\0';
	}
	if (i < 0)
		return (free(out), NULL);
	return (out);
}

/* int main()
{
	int		tmp;
	// int		i;
	char	*s;

	tmp = open("test1.txt", O_RDONLY);
	// i = 0;
	s = get_next_line(tmp);
	printf("%s", s);
	free(s);
	// s = malloc(1);
	// while (s)
	// {
	// 	if (i)
	// 		outf("%s", s);
	// 	free(s);
	// 	s = get_next_line(tmp);
	// 	if (s)
	// 		i++;
	// }
	// free(s);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:34:06 by Mal               #+#    #+#             */
/*   Updated: 2025/07/21 06:15:16 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/* #include "get_next_line_utils_bonus.c" */

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*out;
	int			i;

	out = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (!*buf[fd])
		{
			i = read(fd, buf[fd], BUFFER_SIZE);
			if (i <= 0)
				break ;
			buf[fd][i] = '\0';
		}
		if (ft_gnl_strchr(buf[fd], '\n'))
			return (full_line(out, buf[fd]));
		out = ft_gnl_strjoin(out, buf[fd]);
		*buf[fd] = '\0';
	}
	if (i < 0)
		return (free(out), NULL);
	return (out);
}

/* int main()
{
	int		tmp;
	int		tmp2;
	// int		i;
	char	*s;

	tmp = open("test1.txt", O_RDONLY);
	tmp2 = open("test2.txt", O_RDONLY);
	// i = 0;
	s = get_next_line(tmp);
	printf("%s", s);
	s = get_next_line(tmp2);
	printf("%s", s);
	s = get_next_line(tmp);
	printf("%s", s);
	s = get_next_line(tmp2);
	printf("%s", s);
	s = get_next_line(tmp);
	printf("%s", s);
	s = get_next_line(tmp2);
	printf("%s", s);
	free(s);
}
 */
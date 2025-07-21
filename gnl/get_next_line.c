/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:55:20 by marleand          #+#    #+#             */
/*   Updated: 2025/01/14 13:43:57 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	line = NULL;
	if ((fd < 0 && fd > FOPEN_MAX) || BUFFER_SIZE < 1)
		return (line);
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = fstrjoin(line, buffer);
		if (newline(buffer))
			break ;
		if (read(fd, buffer, BUFFER_SIZE) == -1)
			return (free(line), NULL);
	}
	return (line);
}
/* # include <sys/types.h>
# include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("\nBUFFER SIZE: %i\n", BUFFER_SIZE);
	close(fd);
	return (0);
} */
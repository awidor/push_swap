/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:36:17 by awidor            #+#    #+#             */
/*   Updated: 2025/07/23 15:30:30 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_newline(char *stash, size_t stash_len)
{
	size_t	i;

	i = 0;
	while (i < stash_len)
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	append(char **line, const char *stash, size_t stash_len)
{
	char	*combined;
	size_t	existing_len;

	existing_len = 0;
	if (*line != NULL)
		existing_len = ft_strlen(*line);
	combined = malloc(existing_len + stash_len + 1);
	if (combined == NULL)
		return (0);
	if (*line != NULL)
		ft_memcpy(combined, *line, existing_len);
	ft_memcpy(combined + existing_len, stash, stash_len);
	combined[existing_len + stash_len] = '\0';
	free(*line);
	*line = combined;
	return (1);
}

static char	*extract_line(char **line, char *stash, size_t *stash_len,
		size_t nl_pos)
{
	size_t	remaining;

	if (append(line, stash, nl_pos + 1) == 0)
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	remaining = *stash_len - (nl_pos + 1);
	ft_memmove(stash, stash + nl_pos + 1, remaining);
	*stash_len = remaining;
	stash[remaining] = '\0';
	return (*line);
}

static char	*read_and_process(int fd, char **line, char *stash,
		size_t *stash_len)
{
	int	nl_pos;
	int	read_bytes;

	while (1)
	{
		nl_pos = find_newline(stash, *stash_len);
		if (nl_pos >= 0)
			return (extract_line(line, stash, stash_len, nl_pos));
		if (append(line, stash, *stash_len) == 0)
			return (free(*line), *stash_len = 0, NULL);
		*stash_len = 0;
		read_bytes = read(fd, stash, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			*stash_len = 0;
			return (free(*line), NULL);
		}
		if (read_bytes == 0)
		{
			if (*line != NULL && **line == '\0')
				return (free(*line), NULL);
			return (*line);
		}
		*stash_len = read_bytes;
	}
}

char	*get_next_line(int fd)
{
	static char		stash[BUFFER_SIZE + 1] = {0};
	static size_t	stash_len = 0;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_and_process(fd, &line, stash, &stash_len));
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	size_t	i;
// 	char	*line;

// 	i = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL && i < 3)
// 	{
// 		printf("%zu: %s", i, line);
// 		i++;
// 		free(line);
// 	}
// 	if (line != NULL)
// 		free(line);
// 	close(fd);
// 	return (0);
// }

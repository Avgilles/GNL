/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavraam <gavraam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:27:06 by gavraam           #+#    #+#             */
/*   Updated: 2026/01/02 16:14:33 by gavraam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_to_stash(char *stash, char *buffer)
{
	char	*temp;

	if (!stash || !buffer)
		return ("");
	temp = ft_strjoin(stash, buffer);
	free(stash);
	return (temp);
}

char	*extract_line(char *stash)
{
	size_t	i;		
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

char	*obtain_remaining_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i + 1);
	free(stash);
	return (new_stash);
}

char	*read_from_file(int fd, char *stash)
{
	ssize_t		read_byte;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (read_byte > 0 && !ft_strchr(stash, '\n'))
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (free(buffer), free(stash), NULL);
		buffer[read_byte] = '\0';
		stash = append_to_stash(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = read_from_file(fd, stash);
	if (!stash || stash[0] == '\0')
		return (free(stash), stash = NULL, NULL);
	line = extract_line(stash);
	stash = obtain_remaining_stash(stash);
	return (line);
}

/*
int	main(void)
{
	char	*line = NULL;
	int		i;
	int		fd1;

	fd1 = open("test.txt", O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd1)) != NULL)
	{
		// printf("%s", line);
		printf("line [%02d]: %s", i, line);
		i++;
		free(line);
	}
	// line = get_next_line(fd1);
	// printf("line [%02d]: %s", 1, line);
	// line = get_next_line(fd1);
	// printf("line [%02d]: %s", 2, line);
	// line = get_next_line(fd1);
	// printf("line [%02d]: %s", 3, line);

	close(fd1);
	return (0);
}
*/

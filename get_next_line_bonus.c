/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavraam <gavraam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:27:06 by gavraam           #+#    #+#             */
/*   Updated: 2026/01/02 16:15:51 by gavraam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char		*stash[1024];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc(sizeof(char) * 1);
		if (!stash[fd])
			return (NULL);
		stash[fd][0] = '\0';
	}
	stash[fd] = read_from_file(fd, stash[fd]);
	if (!stash[fd] || stash[fd][0] == '\0')
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	line = extract_line(stash[fd]);
	stash[fd] = obtain_remaining_stash(stash[fd]);
	return (line);
}
/*
int	main(void)
{
	char	*line = NULL;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test_2.txt", O_RDONLY);
	fd3 = open("test_3.txt", O_RDONLY);
	printf("\n 1 -------------- \n");
	
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("\n 2 -------------- \n");
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("\n 3 -------------- \n");
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/
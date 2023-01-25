/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:23:21 by nel-mous          #+#    #+#             */
/*   Updated: 2022/11/17 12:21:15 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	isline(char *save)
{
	int	i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*re_save(int fd, char *save)
{
	char	buffer[BUFFER_SIZE + 1];
	int		n;

	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free(save);
			save = NULL;
			break ;
		}
		buffer[n] = '\0';
		save = ft_strjoin(save, buffer);
		if (isline(save))
			break ;
	}
	return (save);
}

char	*return_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = '\n';
		i += 1;
	}
	line[i] = '\0';
	return (line);
}

char	*sponge_line(char *save)
{
	char	*newsave;
	int		start;
	int		len;

	start = 0;
	while (save[start] && save[start] != '\n')
		start++;
	if (!save[start])
	{
		free(save);
		return (NULL);
	}
	len = ft_strlen(save) - (start + 1);
	newsave = ft_substr(save, start + 1, len);
	free(save);
	return (newsave);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = re_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = return_line(save[fd]);
	save[fd] = sponge_line(save[fd]);
	return (line);
}

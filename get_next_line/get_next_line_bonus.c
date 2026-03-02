/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboubaza <mboubaza@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 05:09:24 by mboubaza          #+#    #+#             */
/*   Updated: 2025/12/21 16:10:00 by mboubaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*free_buf(char *buffer)
{
	if (buffer)
		free(buffer);
	return (NULL);
}

static char	*new_line(char *tmp, int fd)
{
	char	*buffer;
	char	*tmptmp;
	int		readed;

	if (!tmp)
		tmp = (char *)ft_calloc(1, sizeof(char));
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free_buf(buffer);
			return (free_buf(tmp));
		}
		buffer[readed] = '\0';
		tmptmp = tmp;
		tmp = ft_strjoin(tmptmp, buffer);
		free_buf(tmptmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free_buf(buffer);
	return (tmp);
}

static char	*the_line(char *tmp, int *start)
{
	int	i;

	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	*start = i;
	if (tmp[i] == '\n')
		return (ft_substr(tmp, 0, *start + 1));
	return (ft_substr(tmp, 0, *start));
}

static char	*the_rest(char *tmp, int start)
{
	int	len;

	if (!tmp[start] || (tmp[start] == '\n' && !tmp[start + 1]))
		return (NULL);
	if (tmp[start] == '\n')
		start++;
	len = ft_strlen(tmp) - start;
	return (ft_substr(tmp, start, len));
}

char	*get_next_line(int fd)
{
	static char	*tmp[1024];
	char		*str;
	char		*tmptmp;
	int			start;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	start = 0;
	tmp[fd] = new_line(tmp[fd], fd);
	if (!tmp[fd])
		return (NULL);
	str = the_line(tmp[fd], &start);
	tmptmp = tmp[fd];
	tmp[fd] = the_rest(tmptmp, start);
	free_buf(tmptmp);
	return (str);
}

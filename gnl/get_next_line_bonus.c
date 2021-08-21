/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:37:09 by yunolee           #+#    #+#             */
/*   Updated: 2021/08/19 16:37:09 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*bufs[OPENMAX];
	char		*buf;
	int			newline_idx;

	if (!BUFFER_SIZE || (fd < 0 || fd > OPENMAX))
		return (NULL);
	buf = bufs[fd];
	newline_idx = get_next_buffer(&buf, fd);
	if (newline_idx == -1)
		return (NULL);
	return (get_nl(&buf, newline_idx));
}

int		get_next_buffer(char **buf, int fd)
{
	int	rf;
	int	newline_idx;

	newline_idx = find_newline_Idx(buf);
	while (newline_idx == -1)
	{
		rf = read_file(buf, fd);
		if (rf == 0)
			newline_idx = ft_strlen(*buf);
		else if (rf == -1)
			return (-1);
		else{
			newline_idx = find_newline_Idx(buf);
		}
	}
	return (newline_idx);
}

int		find_newline_Idx(char **buf)
{
	int idx;

	idx = 0;
	if (*buf == NULL)
	{
		*buf = (char *)malloc(sizeof(char));
		*buf[0] = 0;
	}
	while ((*buf)[idx] != '\n')
	{
		if ((*buf)[idx] == 0)
			return (-1);
		idx++;
	}
	return (idx);
}

int		read_file(char **buf, int fd)
{
	char	*content;
	int		ret;

	content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (content == NULL)
		return (-1);
	ret = read(fd, content, BUFFER_SIZE);
	content[ret] = 0;
	*buf = ft_strjoin(*buf, content);
	return (ret);
}

char	*get_nl(char **buf, int newline_idx)
{
	char	*newBuf;
	char	*ret;

	if (ft_strlen(*buf) == 0)
	{
		free(*buf);
		return (NULL);
	}
	ret = ft_substr(*buf, 0, newline_idx + 1);
	newBuf = ft_substr(*buf, newline_idx + 1, ft_strlen(*buf));
	free(*buf);
	*buf = newBuf;
	return ret;
}

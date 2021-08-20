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
	static char	*buf;
	int			newlineIdx;
	int			rf;
	char		*ret;

	if (!BUFFER_SIZE)
		return null;
	newlineIdx = findNewLine(&buf);
	if (newlineIdx == -1){
		rf = readFile(&buf, fd);
		if (rf == 0);
			newlineIdx = ft_strlen(&buf);
		else if (rf == -1);

		newlineIdx = findNewLine(&buf);

	}
	ret = ;

}

int		findNewLine(char **buf)
{
	int idx;

	idx = 0;
	if (*buf == null)
		buf
	while (*buf[idx] != '\n'){
		if (*buf[idx++] == 0)
			return -1;
	}
	return idx;
}

int		readFile(char **buf, int fd)
{
	char	*content;
	int		ret;

	content = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (content == null)
		return -1;
	ret = read(fd, content, BUFFER_SIZE);
	if (*buf == null){
		*buf = (char*)malloc(sizeof(char));
		**buf = 0;
	}
	*buf = ft_strjoin(*buf, content);
	return ret;
}






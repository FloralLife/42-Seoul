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

	if (!BUFFER_SIZE)
		return null;
	newlineIdx = findNewLine(buf);
	if (newlineIdx == -1){
		readFile(&buf, fd);
		newlineIdx = findNewLine(buf);
	}
}

int		findNewLine(char *buf)
{
	int idx;

	idx = 0;
	while (buf[idx] != '\n'){
		if (buf[idx++] == 0)
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

	)
}






/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 03:23:17 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/02 20:47:32 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_size	readMapSize(char *mapFileName)
{
	int		fd;
	char	*buf;
	int		len;
	t_size	size;

	fd = open(mapFileName, O_RDONLY);
	size.width = 0;
	size.height = 0;
	while (1)
	{
		buf = getNextLine(fd);
		if (buf == NULL)
			break ;
		len = ft_strlen(buf);
		if (size.width == 0)
			size.width = len;
		else if (size.width != len)
			errorHandler("Invalid Map ");
		free(buf);
		size.height++;
	}
	close(fd);
	return (size);
}

t_mapInfo	readMap(char *mapFileName)
{
	int			fd;
	t_mapInfo	mapInfo;
	char		*buf;
	int			idx;

	fd = open(mapFileName, O_RDONLY);
	if (fd == -1)
		errorHandler("Invalid Filename ");
	mapInfo.size = readMapSize(mapFileName);
	mapInfo.map = (char **)malloc(mapInfo.size.height * sizeof(char *));
	if (mapInfo.map == NULL)
		errorHandler("Allocation Fail ");
	idx = 0;
	while (1)
	{
		buf = getNextLine(fd);
		if (buf == NULL)
			break ;
		mapInfo.map[idx++] = buf;
	}
	close(fd);
	validateMap(&mapInfo);
	mapInfo.numOfStep = 0;
	return (mapInfo);
}

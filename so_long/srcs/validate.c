/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 03:09:15 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/01 17:57:26 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkFileName(char *fileName)
{
	int	len;

	len = ft_strlen(fileName);
	if (!(len > 4
			&& fileName[len - 4] == '.'
			&& fileName[len - 3] == 'b'
			&& fileName[len - 2] == 'e'
			&& fileName[len - 1] == 'r'))
		errorHandler("Invalid FileName ");
}

void	checkSurrounded(int row, int col, t_mapInfo mapInfo)
{
	if (row == 0 || row == mapInfo.size.height - 1)
	{
		if (mapInfo.map[row][col] != '1')
		{
			freeMap(mapInfo);
			errorHandler("Not Surrounded Map ");
		}
	}
	else if (col == 0 || col == mapInfo.size.width - 1)
	{
		if (mapInfo.map[row][col] != '1')
		{
			freeMap(mapInfo);
			errorHandler("Not Surrounded Map ");
		}
	}
}

void	countCharacters(char c, int *cntP, int *cntE, int *cntC)
{
	if (c == 'P')
		*cntP += 1;
	else if (c == 'E')
		*cntE += 1;
	else if (c == 'C')
		*cntC += 1;
}

void	validateMap(t_mapInfo mapInfo)
{
	int	i;
	int	j;
	int	cntP;
	int	cntE;
	int	cntC;

	cntP = 0;
	cntE = 0;
	cntC = 0;
	i = -1;
	while (++i < mapInfo.size.height)
	{
		j = -1;
		while (++j < mapInfo.size.width)
		{
			checkSurrounded(i, j, mapInfo);
			countCharacters(mapInfo.map[i][j], &cntP, &cntE, &cntC);
		}
	}
	if (cntP < 1 || cntE < 1 || cntC < 1)
	{
		freeMap(mapInfo);
		errorHandler("Invalid Character Numbers ");
	}
	mapInfo.numOfCollectible = cntC;
}

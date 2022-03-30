/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 03:09:15 by yunolee           #+#    #+#             */
/*   Updated: 2022/03/31 04:21:04 by yunolee          ###   ########.fr       */
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
		errorHandler("Unvalid FileName ");
}

void	validateMap(t_mapInfo mapInfo)
{
	int	i;
	int	j;
	int	cntP;
	int	cntE;
	int	cntC;

	i = 0;
	while (i < mapInfo.size.height)
	{
		j = 0;
		while (j < mapInfo.size.width)
		{
			if (i == 0 || i == mapInfo.size.height - 1)


		}
	}
}

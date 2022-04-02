/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:14:36 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/02 20:47:32 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initImg(t_mlx *mlx)
{
	mlx->blockSize = 48;
	mlx->time = 0;
	mlx->img.pacman[0] = mlx_xpm_file_to_image(mlx->ptr, "images/pacman0.xpm",
			&mlx->blockSize, &mlx->blockSize);
	mlx->img.pacman[1] = mlx_xpm_file_to_image(mlx->ptr, "images/pacman1.xpm",
			&mlx->blockSize, &mlx->blockSize);
	mlx->img.pacman[2] = mlx_xpm_file_to_image(mlx->ptr, "images/pacman2.xpm",
			&mlx->blockSize, &mlx->blockSize);
	mlx->img.pacman[3] = mlx_xpm_file_to_image(mlx->ptr, "images/pacman1.xpm",
			&mlx->blockSize, &mlx->blockSize);
	mlx->img.ghost[0] = mlx_xpm_file_to_image(mlx->ptr, "images/ghost1.xpm",
			&mlx->blockSize, &mlx->blockSize);
	mlx->img.ghost[1] = mlx_xpm_file_to_image(mlx->ptr, "images/ghost2.xpm",
			&mlx->blockSize, &mlx->blockSize);
	mlx->img.door[0] = mlx_xpm_file_to_image(mlx->ptr, "images/openDoor.xpm",
			&mlx->blockSize, &mlx->blockSize);
	mlx->img.door[1] = mlx_xpm_file_to_image(mlx->ptr, "images/closeDoor.xpm",
			&mlx->blockSize, &mlx->blockSize);
	mlx->img.cherry = mlx_xpm_file_to_image(mlx->ptr, "./images/cherry.xpm",
			&mlx->blockSize, &mlx->blockSize);
	mlx->img.wall = mlx_xpm_file_to_image(mlx->ptr, "images/wall.xpm",
			&mlx->blockSize, &mlx->blockSize);
	mlx->img.floor = mlx_xpm_file_to_image(mlx->ptr, "images/floor.xpm",
			&mlx->blockSize, &mlx->blockSize);
}

void	drawSteps(t_mlx mlx, t_mapInfo mapInfo)
{
	char	*steps;

	steps = ft_itoa(mapInfo.numOfStep);
	mlx_string_put(mlx.ptr, mlx.winPtr, 20, 20, 0xDEDEDE, steps);
	free(steps);
}

void	drawImage(t_mlx mlx, t_mapInfo mapInfo, int row, int col)
{
	if (mapInfo.map[row][col] == '1')
		mlx_put_image_to_window(mlx.ptr, mlx.winPtr, mlx.img.wall,
			col * BLOCKSIZE, row * BLOCKSIZE);
	else if (mapInfo.map[row][col] == '0')
		mlx_put_image_to_window(mlx.ptr, mlx.winPtr, mlx.img.floor,
			col * BLOCKSIZE, row * BLOCKSIZE);
	else if (mapInfo.map[row][col] == 'P')
		mlx_put_image_to_window(mlx.ptr, mlx.winPtr,
			mlx.img.pacman[mlx.time / 10 % 4],
			col * BLOCKSIZE, row * BLOCKSIZE);
	else if (mapInfo.map[row][col] == 'E')
		mlx_put_image_to_window(mlx.ptr, mlx.winPtr,
			mlx.img.door[mapInfo.numOfCollectible != 0],
			col * BLOCKSIZE, row * BLOCKSIZE);
	else if (mapInfo.map[row][col] == 'C')
		mlx_put_image_to_window(mlx.ptr, mlx.winPtr, mlx.img.cherry,
			col * BLOCKSIZE, row * BLOCKSIZE);
	else if (mapInfo.map[row][col] == 'Y')
		mlx_put_image_to_window(mlx.ptr, mlx.winPtr,
			mlx.img.ghost[mlx.time / 10 % 2],
			col * BLOCKSIZE, row * BLOCKSIZE);
	drawSteps(mlx, mapInfo);
}

int	drawMap(t_mlx mlx, t_mapInfo mapInfo)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapInfo.size.height)
	{
		j = 0;
		while (j < mapInfo.size.width)
		{
			drawImage(mlx, mapInfo, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	exposeDraw(t_param *param)
{
	param->mlx.time++;
	param->mlx.time %= 100;
	drawMap(param->mlx, param->mapInfo);
	return (0);
}

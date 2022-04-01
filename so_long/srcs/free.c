/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:34:25 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/01 19:34:29 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeMap(t_mapInfo mapInfo)
{
	int	i;

	i = mapInfo.size.height;
	while (i--)
		free(mapInfo.map[i]);
	free(mapInfo.map);
}

void	destroyImg(t_mlx mlx)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (mlx.img.pacman[i])
			mlx_destroy_image(mlx.ptr, mlx.img.pacman[i]);
	i = -1;
	while (++i < 2)
		if (mlx.img.enemy[i])
			mlx_destroy_image(mlx.ptr, mlx.img.enemy[i]);
	i = -1;
	while (++i < 2)
		if (mlx.img.door[i])
			mlx_destroy_image(mlx.ptr, mlx.img.door[i]);
	if (mlx.img.cherry)
		mlx_destroy_image(mlx.ptr, mlx.img.cherry);
	if (mlx.img.wall)
		mlx_destroy_image(mlx.ptr, mlx.img.wall);
	if (mlx.img.floor)
		mlx_destroy_image(mlx.ptr, mlx.img.floor);
}

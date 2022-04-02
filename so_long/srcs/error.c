/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:02:29 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/02 20:26:49 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errorHandler(char *str)
{
	ft_putError("Error\n");
	perror(str);
	exit(0);
}

void	mlxErrorHandler(t_mapInfo mapInfo)
{
	freeMap(mapInfo);
	errorHandler("MiniLibX Function Fail ");
}

void	mlxImageErrorCheck(t_mlx mlx, t_mapInfo mapInfo)
{
	if (!mlx.img.floor ||
			!mlx.img.wall ||
			!mlx.img.pacman[0] ||
			!mlx.img.pacman[1] ||
			!mlx.img.pacman[2] ||
			!mlx.img.pacman[3] ||
			!mlx.img.door[0] ||
			!mlx.img.door[1] ||
			!mlx.img.cherry ||
			!mlx.img.ghost[0] ||
			!mlx.img.ghost[1])
	{
		destroyMlx(mlx);
		freeMap(mapInfo);
		errorHandler("Invalid xpm File ");
	}
}

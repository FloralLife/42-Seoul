/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:49:13 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/02 20:47:32 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exitWindow(t_param *param)
{
	ft_putstr("Game Closed!\n");
	freeMap(param->mapInfo);
	exit(0);
	return (0);
}

void	exitGame(char *msg, t_mlx mlx, t_mapInfo mapInfo)
{
	freeMap(mapInfo);
	destroyMlx(mlx);
	ft_putstr(msg);
	exit(0);
}

void	defeat(t_mlx mlx, t_mapInfo mapInfo)
{
	freeMap(mapInfo);
	destroyMlx(mlx);
	ft_putstr("You Lose!\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_param		param;
	t_mapInfo	mapInfo;
	t_mlx		mlx;

	if (argc != 2)
		errorHandler("Invalid Input ");
	checkFileName(argv[1]);
	mapInfo = readMap(argv[1]);
	mlx.ptr = mlx_init();
	if (mlx.ptr == NULL)
		mlxErrorHandler(mapInfo);
	mlx.winPtr = mlx_new_window(mlx.ptr,
			mapInfo.size.width * 48, mapInfo.size.height * 48, "SOLONG");
	if (mlx.winPtr == NULL)
		mlxErrorHandler(mapInfo);
	initImg(&mlx);
	mlxImageErrorCheck(mlx, mapInfo);
	drawMap(mlx, mapInfo);
	param.mapInfo = mapInfo;
	param.mlx = mlx;
	mlx_hook(mlx.winPtr, KEY_PRESS_EVENT, 0, pressKey, &param);
	mlx_hook(mlx.winPtr, KEY_DESTROY_NOTIFY, 0, exitWindow, &param);
	mlx_loop_hook(mlx.ptr, exposeDraw, &param);
	mlx_loop(mlx.ptr);
}

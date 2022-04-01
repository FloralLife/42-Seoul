/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:49:13 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/01 20:51:21 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	drawMap(mlx, mapInfo);
	param.mapInfo = mapInfo;
	param.mlx = mlx;

	for(int i = 0; i < mapInfo.size.height; i++)
	{
		ft_putstr(mapInfo.map[i]);
		ft_putchar('\n', 1);
	}
	mlx_loop_hook(mlx.ptr, exposeDraw, &param);
	mlx_loop(mlx.ptr);

}

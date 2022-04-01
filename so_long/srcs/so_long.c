/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:49:13 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/01 15:14:15 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mapInfo mapInfo;

	if (argc != 2)
		errorHandler("Invalid Input ");
	checkFileName(argv[1]);
	mapInfo = readMap(argv[1]);
	for(int i = 0; i < mapInfo.size.height; i++)
	{
		ft_putstr(mapInfo.map[i]);
		ft_putchar('\n', 1);
	}


}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:02:29 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/01 17:01:28 by yunolee          ###   ########.fr       */
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

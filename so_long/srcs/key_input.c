/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:24:29 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/02 20:03:48 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(t_position next, t_param *param)
{
	char	nextTile;

	nextTile = param->mapInfo.map[next.y][next.x];
	if (nextTile == '0')
		return (TRUE);
	if (nextTile == 'C')
	{
		param->mapInfo.numOfCollectible--;
		return (TRUE);
	}
	if (nextTile == 'E' && param->mapInfo.numOfCollectible == 0)
		exitGame("Congraturation! You Win!\n", param->mlx,  param->mapInfo);
	if (nextTile == 'Y')
		defeat(param->mlx, param->mapInfo);
	return (FALSE);
}

void	setNextPosition(t_param *param, t_position prev, t_position next)
{
	param->mapInfo.map[prev.y][prev.x] = '0';
	param->mapInfo.map[next.y][next.x] = 'P';
	param->mapInfo.playerPosition.x = next.x;
	param->mapInfo.playerPosition.y = next.y;
	param->mapInfo.numOfStep++;
}

int	pressKey(int type, t_param *param)
{
	t_position	next;
	t_position	prev;

	next = positionFactory(param->mapInfo.playerPosition.x,
			param->mapInfo.playerPosition.y);
	prev = positionFactory(next.x, next.y);
	if (type == KEY_ESC)
		exitGame("Game Closed\n", param->mlx, param->mapInfo);
	if (type == KEY_W || type == KEY_UP)
		next.y--;
	else if (type == KEY_A || type == KEY_LEFT)
		next.x--;
	else if (type == KEY_S || type == KEY_DOWN)
		next.y++;
	else if (type == KEY_D || type == KEY_RIGHT)
		next.x++;
	if (move(next, param))
	{
		setNextPosition(param, prev, next);
		ft_putnbr(param->mapInfo.numOfStep);
		ft_putstr(" step\n");
		enemyMove(param);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:03:16 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/02 20:01:39 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	patrol(t_param *param, int idx)
{
	static int	dx[4] = {0, 1, 0, -1};
	static int	dy[4] = {-1, 0, 1, 0};
	t_enemyInfo	*enemy;
	t_position	next;
	t_position	prev;

	enemy = &param->mapInfo.enemies[idx];
	prev = positionFactory(enemy->pos.x, enemy->pos.y);
	next = positionFactory(prev.x + dx[enemy->dir],	prev.y + dy[enemy->dir]);
	if (param->mapInfo.map[next.y][next.x] == '0')
	{
		param->mapInfo.map[prev.y][prev.x] = '0';
		param->mapInfo.map[next.y][next.x] = 'Y';
		enemy->pos = next;
	}
	else if (param->mapInfo.map[next.y][next.x] == 'P')
		defeat(param->mlx, param->mapInfo);
	else
		enemy->dir = (enemy->dir + 1) % 4;
}

void	enemyMove(t_param *param)
{
	int	i;

	i = -1;
	while(++i < param->mapInfo.numOfEnemies)
		patrol(param, i);
}

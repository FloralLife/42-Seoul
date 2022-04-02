/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:16:40 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/02 20:47:32 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_position	positionFactory(int x, int y)
{
	t_position	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_enemyInfo	enemyInfoFactory(int x, int y, int dir)
{
	t_enemyInfo	ret;

	ret.pos.x = x;
	ret.pos.y = y;
	ret.dir = dir;
	return (ret);
}

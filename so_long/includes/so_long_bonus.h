/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:39:05 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/02 20:46:17 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "mlx.h"

# define BUFFER_SIZE 42
# define OPENMAX 4096
# define BLOCKSIZE 48
# define TRUE 1
# define FALSE 0

# define KEY_PRESS_EVENT 2
# define KEY_DESTROY_NOTIFY 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

typedef struct s_size
{
	int	width;
	int	height;
}	t_size;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_enemyInfo
{
	t_position	pos;
	int			dir;
}	t_enemyInfo;

typedef struct s_mapInfo
{
	t_size		size;
	char		**map;
	int			numOfCollectible;
	int			numOfEnemies;
	int			numOfStep;
	t_position	playerPosition;
	t_enemyInfo	*enemies;
}	t_mapInfo;

typedef struct s_img
{
	void	*pacman[4];
	void	*ghost[2];
	void	*door[2];
	void	*cherry;
	void	*wall;
	void	*floor;
}	t_mlxImg;

typedef struct s_mlx
{
	void		*ptr;
	void		*winPtr;
	int			time;
	int			blockSize;
	t_mlxImg	img;
}	t_mlx;

typedef struct s_param
{
	t_mlx		mlx;
	t_mapInfo	mapInfo;
}	t_param;

char		*getNextLine(int fd);
t_mapInfo	readMap(char *mapFileName);
void		validateMap(t_mapInfo *mapInfo);
void		checkFileName(char *fileName);
void		initImg(t_mlx *mlx);
int			drawMap(t_mlx mlx, t_mapInfo mapInfo);
int			exposeDraw(t_param *param);
int			pressKey(int type, t_param *param);
void		enemyMove(t_param *param);

void		exitGame(char *msg, t_mlx mlx, t_mapInfo mapInfo);
void		defeat(t_mlx mlx, t_mapInfo mapInfo);

int			ft_strlen(char *str);
char		*ft_substr(char *str, int start, int end);
char		*ft_strjoin(char *a, char *b);
char		*ft_itoa(int n);

t_position	positionFactory(int x, int y);
t_enemyInfo	enemyInfoFactory(int x, int y, int dir);

void		freeMap(t_mapInfo mapInfo);
void		destroyMlx(t_mlx mlx);

void		errorHandler(char *str);
void		mlxErrorHandler(t_mapInfo mapInfo);
void		mlxImageErrorCheck(t_mlx mlx, t_mapInfo mapInfo);

void		ft_putchar(char c, int fd);
void		ft_putstr(char *str);
void		ft_putError(char *errMsg);
void		ft_putnbr(int num);

#endif

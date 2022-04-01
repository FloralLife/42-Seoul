/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:39:05 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/01 20:23:43 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

typedef struct s_mapInfo
{
	t_size	size;
	char	**map;
	int		numOfCollectible;
}	t_mapInfo;

typedef struct s_img
{
	void	*pacman[4];
	void	*enemy[2];
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
void		validateMap(t_mapInfo mapInfo);
void		checkFileName(char *fileName);
void		initImg(t_mlx *mlx);
int			drawMap(t_mlx mlx, t_mapInfo mapInfo);
int			exposeDraw(t_param *param);

int			ft_strlen(char *str);
char		*ft_substr(char *str, int start, int end);
char		*ft_strjoin(char *a, char *b);

void		freeMap(t_mapInfo mapInfo);
void		destroyImg(t_mlx mlx);

void		errorHandler(char *str);
void		mlxErrorHandler(t_mapInfo mapInfo);

void		ft_putchar(char c, int fd);
void		ft_putstr(char *str);
void		ft_putError(char *errMsg);
void		ft_putnbr(int num);

#endif

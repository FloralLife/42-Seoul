/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:39:05 by yunolee           #+#    #+#             */
/*   Updated: 2022/04/01 14:59:11 by yunolee          ###   ########.fr       */
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
# define TRUE 1
# define FALSE 0

typedef struct s_size
{
	int	width;
	int	height;
}	t_size;

typedef struct s_mapInfo
{
	t_size	size;
	char	**map;
}	t_mapInfo;

int			ft_strlen(char *str);
char		*ft_substr(char *str, int start, int end);
char		*ft_strjoin(char *a, char *b);
void		freeMap(t_mapInfo mapInfo);

void		errorHandler(char *str);
void		checkFileName(char *fileName);

void		ft_putchar(char c, int fd);
void		ft_putstr(char *str);
void		ft_putError(char *errMsg);
void		ft_putnbr(int num);

char		*getNextLine(int fd);
void		validateMap(t_mapInfo mapInfo);
t_mapInfo	readMap(char *mapFileName);

#endif

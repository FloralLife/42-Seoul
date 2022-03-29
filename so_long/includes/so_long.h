/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:39:05 by yunolee           #+#    #+#             */
/*   Updated: 2022/03/30 03:08:55 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 42
# define OPENMAX 4096

int		ft_strlen(char *str);
char	*ft_substr(char *str, int start, int end);
char	*ft_strjoin(char *a, char *b);

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int num);

char	*get_next_line(int fd);


#endif

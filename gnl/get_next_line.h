/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:37:32 by yunolee           #+#    #+#             */
/*   Updated: 2021/08/19 16:37:32 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define OPENMAX 1000

# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>

char	*get_next_line(int fd);
int		find_newline_Idx(char **buf);
int		get_next_buffer(char **buf, int fd);
int		read_file(char **buf, int fd);
char	*get_nl(char **buf, int newline_idx);

int		ft_strlen(char *str);
char	*ft_substr(char *str, int start, int end);
char	*ft_strjoin(char *a, char *b);

#endif


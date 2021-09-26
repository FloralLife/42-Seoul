/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:37:32 by yunolee           #+#    #+#             */
/*   Updated: 2021/09/27 00:38:14 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define OPENMAX 4096

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		find_newline_Idx(char **buf);
int		find_next_line(char **buf, int fd);
int		read_file(char **buf, int fd);
char	*get_nl(char **buf, int newline_idx);

int		ft_strlen(char *str);
char	*ft_substr(char *str, int start, int end);
char	*ft_strjoin(char *a, char *b);

#endif

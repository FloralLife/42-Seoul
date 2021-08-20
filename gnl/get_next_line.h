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

# define OPENMAX

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

int		ft_strlen(char *str);
char	*ft_substr(char *str, int start, int end);
char	*ft_strjoin(char *a, char *b);


#endif


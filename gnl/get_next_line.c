/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:37:09 by yunolee           #+#    #+#             */
/*   Updated: 2021/08/19 16:37:09 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd){
	static char	*buf;



}

int		findNewLine(char *buf){
	int idx;

	idx = 0;
	while (buf[idx] != '\n'){
		if (buf[idx++] == 0)
			return -1;
	}
	return idx;
}






/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:49:13 by yunolee           #+#    #+#             */
/*   Updated: 2022/03/31 03:52:52 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		errorHandler("Unvalid Input ");
	checkFileName(argv[1]);
	map = readMap(argv[1]);
	int i = 8;
	while (i--){
		printf("%s\n",map[i]);
	}


}
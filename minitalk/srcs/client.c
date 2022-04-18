/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:34:58 by yunolee           #+#    #+#             */
/*   Updated: 2022/02/23 00:34:58 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	cnt;
	int	bit;

	cnt = 8;
	while (cnt--)
	{
		bit = (c >> cnt) & 1;
		if (bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(125);
	}
}

void	send_msg(int pid, char *msg)
{
	while (*msg)
	{
		send_char(pid, *msg);
		msg++;
	}
}

int	main(int argc, char *argv[])
{
	char	*msg;
	int		pid;

	if (argc != 3 || !is_integer(argv[1]) || !*argv[2])
	{
		ft_putstr("Bad Request\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	if (pid <= 100 || pid >= 4194304)
	{
		ft_putstr("Bad Request\n");
		return (0);
	}
	send_msg(pid, msg);
}

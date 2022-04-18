/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:34:53 by yunolee           #+#    #+#             */
/*   Updated: 2022/02/23 00:34:53 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	buf = 0;
	static int	cnt = 0;
	static int	pid = 0;

	(void)context;
	if (pid == 0 || pid != info->si_pid)
	{
		pid = info->si_pid;
		buf = 0;
		cnt = 0;
		ft_putchar('\n');
	}
	if (sig == SIGUSR1)
		buf |= 1;
	cnt++;
	if (cnt == 8)
	{
		ft_putchar(buf);
		buf = 0;
		cnt = 0;
		return ;
	}
	buf <<= 1;
}

int	main(void)
{
	struct sigaction	act;

	ft_putstr("Server PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}

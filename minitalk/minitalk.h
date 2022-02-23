/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:41:44 by yunolee           #+#    #+#             */
/*   Updated: 2022/02/23 00:41:44 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		is_integer(char *str);

#endif

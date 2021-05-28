/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:49:23 by yunolee           #+#    #+#             */
/*   Updated: 2021/05/23 17:50:10 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

void	ft_bzero(void *ptr, size_t n);
void	*ft_memchr(const void *ptr, int value, size_t n);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *ptr, int value, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *str, const char *find, size_t n);

#endif

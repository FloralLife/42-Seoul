/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:57:25 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/02 23:58:01 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_digit(unsigned int n)
{
	int cnt;

	cnt = 0;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	int				sign;
	int				i;
	char			*a;
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		sign = 1;
		num = -n;
	}
	else
		sign = 0;
	i = sign;
	i += count_digit(num);
	a = malloc(i + 1);
	a[i--] = 0;
	while (num)
	{
		a[i--] = num % 10 + '0';
		num /= 10;
	}
	if (sign == 1)
		a[0] = '-';
	return (a);
}


#include <limits.h>
int main(){
	printf("%s\n", ft_itoa(INT_MAX));
}

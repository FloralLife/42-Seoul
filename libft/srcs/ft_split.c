/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 01:34:50 by yunolee           #+#    #+#             */
/*   Updated: 2021/06/12 18:49:04 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_split(char const *s, char c)
{
	int		before;
	int		i;
	int		cnt;

	i = 0;
	before = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (before == 0)
			{
				cnt++;
				before = 1;
			}
		}
		else if (before == 1)
			before = 0;
		i++;
	}
	return (cnt);
}

char	*find_word(char const *s, int *start, char c)
{
	int		cnt;
	char	*word;
	int		i;

	cnt = 0;
	while (s[*start + cnt] && s[*start + cnt] != c)
		cnt++;
	word = malloc(cnt + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < cnt)
	{
		word[i] = s[*start + i];
		i++;
	}
	word[i] = 0;
	*start += cnt;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		cnt;
	int		i;
	int		n;

	cnt = count_split(s, c);
	str = (char**)malloc(cnt * sizeof(char*) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	n = 0;
	while (n < cnt)
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		str[n] = find_word(s, &i, c);
		if (str[n] == NULL)
			return (NULL);
		n++;
	}
	str[cnt] = 0;
	return (str);
}

int main(){
	char **spl = ft_split(" 1 2 3 4 5         " ,  ' ');
	for(int i = 0; i< 8; i++){
		printf("[%s]\n", spl[i]);
	}
}

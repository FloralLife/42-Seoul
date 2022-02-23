/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunolee <yunolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:49:09 by yunolee           #+#    #+#             */
/*   Updated: 2021/10/26 22:49:09 by yunolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(){
	int i= -123;
	char c = '2';
	char *str = NULL;
	unsigned int ui = 123;

	// printf("%d\n", ft_printf("%%c : %c\n", c));
	// printf("%d\n", printf("%%c : %c\n", c));
	// printf("%d\n", ft_printf("%%s : %s\n", NULL));
	// printf("%d\n", ft_printf("%%s : %s\n", NULL));
	// printf("%d\n", printf("%%p : %p\n", &i));
	// printf("%d\n", ft_printf("%%p : %p\n", &i));
	// printf("%d\n", printf("%%d : %d\n", i));
	// printf("%d\n", ft_printf("%%d : %d\n", i));
	// printf("%d\n", printf("%%i : %i\n", i));
	// printf("%d\n", ft_printf("%%i : %i\n", i));
	// printf("%d\n", printf("%%u : %u\n", ui));
	// printf("%d\n", ft_printf("%%u : %u\n", ui));
	// printf("%d\n", printf("%%x : %x\n", i));
	// printf("%d\n", ft_printf("%%x : %x\n", i));
	// printf("%d\n", printf("%%X : %X\n", i));
	// printf("%d\n", ft_printf("%%X : %X\n", i));



	printf("%d\n", printf("%%c : %c\n%%s : %s\n%%p : %p\n%%d : %d\n%%i : %i\n%%u : %u\n%%x : %x\n%%X : %X\n\n", c, str, &i, i, i, ui, i, i));
	printf("%d\n", ft_printf("%%c : %c\n%%s : %s\n%%p : %p\n%%d : %d\n%%i : %i\n%%u : %u\n%%x : %x\n%%X : %X\n\n", c, str, &i, i, i, ui, i, i));
}

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

int main(){
	int i= -123;
	char c = '2';
	char *str = NULL;
	unsigned int ui = 123;

	// ft_printf("%%c : %c\n", c);
	// ft_printf("%%s : %s\n", str);
	// ft_printf("%%p : %p\n", &i);
	// ft_printf("%%d : %d\n", i);
	// ft_printf("%%i : %i\n", i);
	// ft_printf("%%u : %u\n", u
	// ft_printf("%%x : %x\n", i);



	ft_printf("%%c : %c\n%%s : %s\n%%p : %p\n%%d : %d\n%%i : %i\n%%u : %u\n%%x : %x\n%%X : %X\n\n", c, str, 0, i, i, ui, i, i);
	printf("%%c : %c\n%%s : %s\n%%p : %p\n%%d : %d\n%%i : %i\n%%u : %u\n%%x : %x\n%%X : %X\n", c, str, 0, i, i, ui, i, i);

}

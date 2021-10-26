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

int main(){
	int i= 32;
	char c = '2';
	char str[23] = "helloworld";
	unsigned int ui = 123;

	// ft_printf("%%c : %c\n", c);
	// ft_printf("%%s : %s\n", str);
	// ft_printf("%%p : %p\n", &i);
	// ft_printf("%%d : %d\n", i);
	// ft_printf("%%i : %i\n", i);
	// ft_printf("%%u : %u\n", ui);
	// ft_printf("%%x : %x\n", i);



	ft_printf("%%c : %c\n%%s : %s\n%%p : %p\n%%d : %d\n%%i : %i\n%%u : %u\n%%x : %x\n%%x : %x\n", c, str, &i, i, i, ui, i);

}

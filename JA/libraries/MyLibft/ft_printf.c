/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:15:07 by juan-anm          #+#    #+#             */
/*   Updated: 2023/06/02 13:05:06 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	val;
	int		i;
	int		res;
	int		tmp;

	va_start(val, str);
	tmp = 0;
	res = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
			tmp = (ft_typesort(val, (char)str[++i]));
		else
			tmp = (ft_putchars(str[i]));
		if (tmp == -1)
			return (-1);
		res += tmp;
	i++;
	}
	va_end(val);
	return (res);
}

int	ft_typesort(va_list val, char c)
{
	int	temp;

	temp = 0;
	if (c == 'c')
		return (ft_putchars(va_arg(val, int)));
	else if (c == 's')
		return (ft_putstrs(va_arg(val, char *)));
	else if (c == 'i' || c == 'd' )
		return (ft_putnbrs(va_arg(val, int), 0));
	else if (c == 'u')
		return (ft_unsputnbrs(va_arg(val, unsigned int), 0));
	else if (c == 'x' || c == 'X')
		return (ft_base_cnvrt(va_arg(val, int), c));
	else if (c == '%')
		return (ft_putchars('%'));
	else if (c == 'p')
	{
		temp = write(1, "0x", 2);
		if (temp == -1)
			return (-1);
		temp += (ft_base_pointer((unsigned long)va_arg(val, void *)));
		return (temp);
	}
	else
		return (0);
}
/*
#include <stdio.h>
int main(void)
{
	char			c			= 	'A';
	char			*str		=	"Hello World!!!";
	void			*pointer	=	&str;
	double			decimal		=	3.141516;	
	int				integer		=	-2147483648;
	unsigned int	unsigdec	=	4294967295;
	unsigned int	HEX			=	255222;
	unsigned int	hex			=	255222;
	int 			res;

//// GREEN TEXT\033[1;32m /////
//// RED TEXT \033[1;31m  /////
//// RESET TEXT \033[1;0m /////

printf("\033[1;35m///////test Char////////\n");
	printf("\033[1;31mSF = Char\n");	
	res = printf("%c", c);
	printf(" integer return = %i \n", res);
    		printf("\033[1;32mFT = Char\n");	
			res = ft_printf("%c", c);
			printf(" integer return = %i \n\n", res);

printf("\033[1;35m///////test String////////\n");
	printf("\033[1;31mSF = str\n");	
	res = printf("%s", str);
	printf(" integer return = %i \n", res);
    		printf("\033[1;32mFT = str\n");	
			res = ft_printf("%s", str);
			printf(" integer return = %i \n\n", res);

printf("\033[1;35m///////test Integers////////\n");
	printf("\033[1;31mSF = Int\n");	
	res = printf("%i", integer);
	printf(" integer return = %i \n", res);
    		printf("\033[1;32mFT = int\n");	
			res = ft_printf("%i", integer);
			printf(" integer return = %i \n\n", res);

printf("\033[1;35m///////test Unsigned int////////\n");
	printf("\033[1;31mSF = Unsigned\n");	
	res = printf("%u", unsigdec);
	printf(" integer return = %i \n", res);
    		printf("\033[1;32mFT = int\n");	
			res = ft_printf("%u", unsigdec);
			printf(" integer return = %i \n\n", res);

printf("\033[1;35m///////test hex////////\n");
	printf("\033[1;31mSF = hex\n");	
	res = printf("%x", hex);
	printf(" integer return = %i \n", res);
    		printf("\033[1;32mFT = hex\n");	
			res = ft_printf("%x", hex);
			printf(" integer return = %i \n\n", res);

printf("\033[1;35m///////test HEX////////\n");
	printf("\033[1;31mSF = HEX\n");	
	res = printf("%X", HEX);
	printf(" integer return = %i \n", res);
    		printf("\033[1;32mFT = HEX\n");	
			res = ft_printf("%X", HEX);
			printf(" integer return = %i \n\n", res);

printf("\033[1;35m///////test Pointers////////\n");
	printf("\033[1;31mSF = Pointer\n");	
	res = printf("%pp", pointer);
	printf(" integer return = %i \n", res);
    		printf("\033[1;32mFT = HEX\n");	
			res = ft_printf("%pp", pointer);
			printf(" integer return = %i \n\n", res);

printf("\033[1;35m///////test Random////////\n");
	printf("\033[1;31mSF = Random\n");	
	res = printf("%pp", pointer);
	printf(" integer return = %i \n", res);
    		printf("\033[1;32mFT = HEX\n");	
			res = ft_printf("%pp", pointer);
			printf(" integer return = %i \n\n", res);


}*/

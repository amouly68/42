

#include <stdio.h>
#include "libftprintf.h"

int main()
{
	int a;
	
	printf("Salut\n");
	a = printf("Salut\n");
	printf("%d", a);	
	ft_printf("Salut");
	a = ft_printf("Salut\n");
	printf("%d", a);	
}

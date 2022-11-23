#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("retour = %d\n", ft_printf("%d\n", 200000));
	printf("%d", 200000);

}

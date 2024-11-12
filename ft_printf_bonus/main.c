#include "includes/ft_printf.h"

int	main(void)
{
	int	one;
	int	two;

	one = ft_printf("My : %-10.1s\n", "-42");
	two = printf("Re : %-10.1s\n", "-42");

	printf("My printf = %d\n", one);
	printf("Re printf = %d\n", two);
}

//Add null gestion w flags
//Hexa_len fine with ft_put_flags ?
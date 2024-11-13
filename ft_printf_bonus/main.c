#include "includes/ft_printf.h"

int	main(void)
{
	int	one;
	int	two;

	one = ft_printf("%-.09s\n", "test");
	two = printf("%-.09s\n", "test");

	printf("My printf = %d\n", one);
	printf("Re printf = %d\n", two);
}

//Add null gestion w flags
//Hexa_len fine with ft_put_flags ?
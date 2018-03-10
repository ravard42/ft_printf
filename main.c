#include "ft_printf.h"
#include <locale.h>


int		main()
{
	int			i;
	char		recup[256] = {0};
	
	printf("\n%d\n", printf("!%#-2.11zx!", -656523068));
	printf("\n%d\n", ft_printf("!%#-2.11zx!", -656523068));
	printf("\n%d\n", printf("!%#-2.11zx!", -656523068));
	printf("\n%d\n", ft_printf("!%#-2.11zx!", -656523068));
	printf("\n%d\n", printf("42%#-.11x42", -1855773440));
	printf("\n%d\n", ft_printf("42%#-.11x42", -1855773440));
	return 0;
}

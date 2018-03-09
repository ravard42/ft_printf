#include "ft_printf.h"
#include <locale.h>


int		main()
{
	int			i;
	char		recup[256] = {0};
	
	//printf("%d\n", ft_sprintf(recup, "plop%c coLcou\n%d", '\0', 5));
	printf("\nprintf : %d\n", ft_printf("plop %c est quoi se bordel %d", 1, 4));
	//i = ft_printf("%c coucou\n", 0);
	//printf("printf return %d\n", i);
	//write(1, recup, ft_sprintf(recup, "plop%c coLcou\n%d", '\0', 5));
	//printf("sprintf renvoi %d :\n --->%s\n", i, recup);
	return 0;
}

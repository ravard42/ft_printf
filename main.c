#include "ft_printf.h"
#include <locale.h>


int		main()
{
	int			i;
	char		recup[256] = {0};
	
	//i = ft_printf("%c coucou\n", 0);
	//printf("printf return %d\n", i);
	write(1, recup, ft_sprintf(recup, "plop%c coucou\n%d", '\0', 5));
	//printf("sprintf renvoi %d :\n --->%s\n", i, recup);
	return 0;
}

#include "ft_printf.h"
#include <locale.h>


int		main()
{
	int			i;
	char		recup[256] = {0};
	
	printf("\n%d\n", printf("^.^/%48.52ls^.^/", L""));
	printf("\n%d\n", ft_printf("^.^/%48.52ls^.^/", L""));
	return 0;
}

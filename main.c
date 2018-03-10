#include "ft_printf.h"
#include <locale.h>


int		main()
{
	int			i;
	char		recup[256] = {0};
	
	ft_printf("!%11.24ls!", L"(null)");
	return 0;
}

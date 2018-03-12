#include "ft_printf.h"
#include <locale.h>


int		main()
{
	int			i;
	char		recup[256] = {0};
	
	printf("%d\n", ft_printf("%b", 55));
	printf("%d\n", ft_printf("%lb", -1));
	
	return 0;
}

#include "ft_printf.h"
#include <locale.h>

# define BS 100

int		main()
{
	int			i;
	char		recup[BS] = {0};

	setlocale(LC_ALL, "");	
//	ft_printf("%C\n", 0xfff);
//	printf("<----printf renvoi : %d---->\n\n", printf("d->%50d\no->%#.7o\nu->%04u\nx->%#5x\nc->%4c\nC->%C\ns->%5s\nS->%S\npercent->%42%\n", 42, 53, -1, 0, 0, 0xfff, "lu les ptis loups", L""));
	printf("<----ft_printf renvoi : %d---->\n", ft_printf("d->%50d\no->%#.7o\nu->%04u\nx->%#5x\nc->%4c\nC->%C\ns->%5s\nS->%S\npercent->%42%\nbin->%lb\n", 42, 53, -1, 42, 42, 0xfff, "lu les ptis loups", L"", -1));
	printf("\n\n\n\n\n<----ft_sprintf renvoi : %d---->\n", ft_sprintf(recup, "d->%50d\no->%#.7o\nu->%04u\nx->%#5x\nc->%4c\nC->%C\ns->%5s\nS->%S\npercent->%42%\nbin->%lb\n", 42, 53, -1, 42, 42, 0xfff, "lu les ptis loups", L"", -1));
	printf("%s\n", recup);
	ft_memset(recup, 0, BS);




//	printf("ft_sprintf renvoi -> %d\n", ft_sprintf(recup, "coucou %050d", 55));
//	printf("%s\n", recup);
//	ft_memset(recup, 0, BS);
//	printf("ft_sprintf renvoi -> %d\n", ft_sprintf(recup, "%04o", 55));
//	printf("%s\n", recup);
//	ft_memset(recup, 0, BS);
//	printf("ft_sprintf renvoi -> %d\n", ft_sprintf(recup, "%04u", 55));
//	printf("%s\n", recup);
//	ft_memset(recup, 0, BS);
//	printf("ft_sprintf renvoi -> %d\n", ft_sprintf(recup, "%#04x", 55));
//	printf("%s\n", recup);
//	ft_memset(recup, 0, BS);
//	printf("ft_sprintf renvoi -> %d\n", ft_sprintf(recup, "%#-4c", 0));
//	printf("%s\n", recup);
//	ft_memset(recup, 0, BS);
//	printf("ft_sprintf renvoi -> %d\n", ft_sprintf(recup, "%#-4C", 0xfff));
//	printf("%s\n", recup);
//	ft_memset(recup, 0, BS);
//	printf("ft_sprintf renvoi -> %d\n", ft_sprintf(recup, "%5s", "lu les ptis loups"));
//	printf("%s\n", recup);
//	ft_memset(recup, 0, BS);
//	printf("ft_sprintf renvoi -> %d\n", ft_sprintf(recup, "%042%", "lu les ptis loups"));
//	printf("%s\n", recup);
//	ft_memset(recup, 0, BS);
//	printf("ft_sprintf renvoi -> %d\n", ft_sprintf(recup, "%lb\n%lb", -1, -2));
//	printf("%s\n", recup);
//	ft_memset(recup, 0, BS);
	
	return 0;
}

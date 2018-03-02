#include "ft_printf.h"
#include <locale.h>


int		main()
{
	char		utf_8[5] = {0};
	wchar_t		wc = 254;
	char		*s = "ø";
	int		i;

	//if (MB_CUR_MAX == 1)
	//	setlocale(LC_ALL, "");
	//printf("%lc\n", 254);
	//ft_printf("%lc\n", 254);

	utf_32_to_8(wc, utf_8);
	i = printf("%C", 0xbffe);
	printf("\n%d\n", i);

	return 0;
}

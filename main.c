#include "ft_printf.h"
#include <locale.h>


int		main()
{
	char		utf_8[5] = {0};
	wchar_t		wc = 0xbffe;
	wchar_t		test[5] = {0x1F780, 0};
	char		notastr[5] =  {0, 'a', '2', 'd'};
	char		*s = "ø";
	int			i;

	if (MB_CUR_MAX == 1)
		setlocale(LC_ALL, "");

	printf("\nprintf renvoie : %d\n", printf("%.4ls\n", (wchar_t *)test));
	

	return 0;
}

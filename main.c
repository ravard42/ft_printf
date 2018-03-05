#include "ft_printf.h"
#include <locale.h>


int		main()
{
	wchar_t		*test = L"┬─┬<feff> ノ( ゜-゜ノ)";
	char		recup1[256] = {0};
	char		recup2[256] = {0};
	char		sgf[250];

	if (MB_CUR_MAX == 1)
		setlocale(LC_ALL, "");

	printf("\nsprintf renvoie : %d\n", sprintf(recup1, "%ls\n", test));
	printf("\nft_sprintf renvoie : %d\n", ft_sprintf(recup2, "%ls\n", test));

	printf("recup1 -> %s\n", recup1);
	printf("recup2 -> %s\n", recup2);

	return 0;
}

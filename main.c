#include "ft_printf.h"
#include <locale.h>


int		main()
{
	wchar_t		*test = L"(╯°□°)╯︵ ┻━┻ ";
	char		recup1[256] = {0};
	char		recup2[256] = {0};
	
	if (MB_CUR_MAX == 1)
		setlocale(LC_ALL, "");
	printf("\nsprintf renvoie : %d\n", sprintf(recup1, ">------------<%54.30ls>------------<\n", test));
	printf("\nft_sprintf renvoie : %d\n", ft_sprintf(recup2, ">------------<%54.30ls>------------<\n", test));

	printf("recup1 -> %s\n", recup1);
	printf("recup2 -> %s\n", recup2);

	int		i = 0;

	while ((recup1[i] || recup2[i]) && recup1[i] == recup2[i])
		++i;
	printf("i = %d\n", i);
	printf("%c\n", recup1[53]);
	printf("%c\n", recup2[53]);

	/*
	int		i[2] = {0};	
	i[0] = printf(">------------<%54.30ls>------------<\n", test);
	i[1] = ft_printf(">------------<%54.30ls>------------<\n", test);
	
	printf("i[0] = %d\ni[1] = %d\n", i[0], i[1]);
	return 0;
	*/
}

#include <stdio.h>

bool main(void)
{
	int array[4];

	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");
	printf("Password:");

	scanf("%d", array);
	if (array[0] != 5276)
	{
		puts("\nInvalid Password!");
	}
	else
	{
		puts("\nAuthenticated!");
		system("/bin/sh");
	}
	return array[0] != 5276;
}

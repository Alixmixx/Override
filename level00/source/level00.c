#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

bool main(void)
{
	int32_t inputValue;

	puts("***********************************");
	puts("*           -Level00 -            *");
	puts("***********************************");
	printf("Password: ");

	scanf("%d", &inputValue);

	if (inputValue != 0x149c) // 5276
	{
		puts("\nInvalid Password!");
	}
	else
	{
		puts("\nAuthenticated!");
		system("/bin/sh");
	}

	return inputValue != 0x149c;
}
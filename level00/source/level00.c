#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

bool main(void)
{
	int32_t inputArray[3];

	puts("***********************************");
	puts("*           -Level00 -            *");
	puts("***********************************");
	printf("Password: ");

	scanf("%d", &inputArray[0]);

	if (inputArray[0] != 0x149c) // 5276
	{
		puts("\nInvalid Password!");
	}
	else
	{
		puts("\nAuthenticated!");
		system("/bin/sh");
	}

	return inputArray[0] != 0x149c;
}
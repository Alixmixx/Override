#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void clear_stdin()
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}

unsigned int get_unum()
{
	unsigned int num;
	fflush(stdout);
	scanf("%u", &num);
	clear_stdin();
	return num;
}

void decrypt(int key)
{
	char buffer[21] = "Q}|u`sfg~sf{}|a3";
	size_t len = strlen(buffer);

	for (size_t i = 0; i < len; i++)
		buffer[i] ^= key;

	if (!strncmp(buffer, "Congratulations!", 17))
		system("/bin/sh");
	else
		puts("Invalid Password!");
}

int test(int arg1, int arg2)
{
	int diff = arg2 - arg1;

	if ((diff > 0 && diff < 10) || (diff > 15 && diff < 22))
		decrypt(diff);
	else
	{
		int randomValue = rand();
		decrypt(randomValue);
	}
}

int main(void)
{
	int userInput;
	srand((unsigned)time(NULL));

	puts("***********************************");
	puts("*               level03         **");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &userInput);
	test(userInput, 0x1337d00d);
	return 0;
}
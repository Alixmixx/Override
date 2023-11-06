#include "stdio.h"
#include "stdlib.h"

char a_user_name[100];

int verify_user_name(void)
{
	char *username = &a_user_name;
	char *expectedName = "dat_wil";

	puts("verifying username....\n");

	for (int i = 0; i < 7; i++)
	{
		if (username[i] != expectedName[i])
			return username[i] - expectedName[i];
	}

	return 0;
}

int verify_user_pass(char *passwordInput)
{
	char *expectedPassword = "admin";

	for (int i = 0; i < 5; i++)
	{
		if (passwordInput[i] != expectedPassword[i])
			return passwordInput[i] - expectedPassword[i];
	}

	return 0;
}

int main(void)
{
	char passwordInput[64] = {0};
	int result;

	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(&a_user_name, 0x100, stdin);

	result = verify_user_name();
	if (result == 0)
	{
		puts("Enter Password: ");
		fgets(passwordInput, 100, stdin);

		result = verify_user_pass(passwordInput);
		if (result == 0 || result != 0)
		{
			puts("nope, incorrect password...\n");
			return 1;
		}
		else
			return 0;
	}
	else
	{
		puts("nope, incorrect username...\n");
		return 1;
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int password[41];
	int pass[41];
	int username[100];
	int bytesRead;
	FILE *passwordFile;

	memset(password, 0, 41);
	memset(pass, 0, 41);
	memset(username, 0, 100);

	passwordFile = fopen("/home/users/level03/.pass", "r");
	if (passwordFile == 0)
	{
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(1);
	}
	bytesRead = fread(pass, 1, 41, passwordFile);
	if (bytesRead != 41)
	{
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		exit(1);
	}
	fclose(passwordFile);

	puts("| You must login to access this system. |");
	printf("--[ Username: ");
	fgets(username, 100, stdin);

	printf("--[ Password: ");
	fgets(password, 100, stdin);
	puts("*****************************************");

	if (strncmp(pass, password, 41) == 0)
	{
		printf("Greetings, %s!\n", username);
		system("/bin/sh");
		return 0;
	}

	printf(username);
	puts(" does not have access!");
	exit(1);
}
#include <stdio.h>

int main(void)
{
    int password[14];
    int pass[6];
    int username[12];
    int ret;
    FILE *fd;

    ret = 0;
    fd = fopen("/home/users/level03/.pass", "r");
    if (fd == 0)
    {
        fwrite("ERROR: failed to open password file\n", 1, 0x24, stderr);
        exit(1);
    }
    ret = fread(pass, 1, 41, fd);
    if (ret != 41)
    {
        fwrite("ERROR: failed to read password file\n", 1, 0x24, stderr);
        exit(1);
    }
    fclose(fd);
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
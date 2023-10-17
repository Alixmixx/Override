#include "stdio.h"
#include "stdlib.h"

int verify_user_name(void)
{
    int iVar1;
    byte *pbVar2;
    byte *pbVar3;
    undefined uVar4;
    undefined uVar5;
    byte bVar6;

    bVar6 = 0;
    uVar4 = &stack0xfffffff4 < (undefined *)0x10;
    uVar5 = &stack0x00000000 == (undefined *)0x1c;
    puts("verifying username....\n");
    iVar1 = 7;
    pbVar2 = &a_user_name;
    pbVar3 = (byte *)"dat_wil";
    do
    {
        if (iVar1 == 0)
            break;
        iVar1 = iVar1 + -1;
        uVar4 = *pbVar2 < *pbVar3;
        uVar5 = *pbVar2 == *pbVar3;
        pbVar2 = pbVar2 + (uint)bVar6 * -2 + 1;
        pbVar3 = pbVar3 + (uint)bVar6 * -2 + 1;
    } while ((bool)uVar5);
    return (int)(char)((!(bool)uVar4 && !(bool)uVar5) - uVar4);
}

int verify_user_pass(char *param_1)

{
    int iVar1;
    char *pbVar2;
    undefined in_CF;
    undefined in_ZF;

    iVar1 = 5;
    pbVar2 = (char *)"admin";
    do
    {
        if (iVar1 == 0)
            break;
        iVar1 = iVar1 + -1;
        in_CF = *param_1 < *pbVar2;
        in_ZF = *param_1 == *pbVar2;
        param_1 = param_1 + 1;
        pbVar2 = pbVar2 + 1;
    } while ((bool)in_ZF);
    return (int)(char)((!(bool)in_CF && !(bool)in_ZF) - in_CF);
}

char a_user_name[100];

int main(void)
{
    char password_buffer[64]; // a verifier
    int is_user_valid;

    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");
    fgets(&a_user_name, 0x100, stdin); // a_user_name is at *0x0804a040
    is_user_valid = verify_user_name();
    if (is_user_valid == 0)
    {
        puts("Enter Password: ");
        fgets(password_buffer, 100, stdin);
        is_user_valid = verify_user_pass(password_buffer);
        if ((is_user_valid == 0) || (is_user_valid != 0))
            puts("nope, incorrect password...\n");
        else
            return 0; // on va jamais rentrer dedans
    }
    else
        puts("nope, incorrect username...\n");

    return 1;
}
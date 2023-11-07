#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    unsigned int a = atoi(argv[1]);
    printf("%u\n", a * 4);
}
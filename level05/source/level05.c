#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)

{
  char bVar1;
  uint uVar2;
  char *pbVar3;
  char bVar4;
  char buffer [100];
  uint counter;
  
  bVar4 = 0;
  counter = 0;
  fgets(buffer,100,stdin);
  counter = 0;
  do {
    uVar2 = 0xffffffff;
    pbVar3 = buffer;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + (uint)bVar4 * -2 + 1;
    } while (bVar1 != 0);
    if (~uVar2 - 1 <= counter) {
      printf(buffer);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if (('@' < buffer[counter]) && (buffer[counter] < '[')) {
      buffer[counter] = buffer[counter] ^ 0x20;
    }
    counter = counter + 1;
  } while( 1 );
}
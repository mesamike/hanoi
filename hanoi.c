#include <stdio.h>
#include <stdlib.h>

void hanoi(unsigned, unsigned, unsigned);

static unsigned moves;

void hanoi(unsigned n, unsigned from, unsigned to)
{
   unsigned other = 6 - from - to;  /* the spare  peg */
   moves++;

   if(n == 1) 
      printf("Top disk on peg %u => peg %u\n", from, to);
   else {
      hanoi(n-1, from, other);
      printf("Top disk on peg %u => peg %u\n", from, to);
      hanoi(n-1, other, to);
   }
}
       

int main(int argc, char **argv) 
{
   unsigned num = 5;    /* default tower size */

   if (argc > 1) 
      num = (unsigned)atoi(argv[1]);
   if(num < 1)  
      printf("Can't move %u disks!\n", num);
   else {
      printf("Moving %u disks from peg 1 to peg 3\n", num);
      hanoi(num, 1, 3);  /*Move tower from peg 1 to peg 3 */
      printf("\nDone! Moved tower of %u disks in %u moves.\n", num, moves);
   }

   return 0;
}

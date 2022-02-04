#include <stdio.h>
#include <stdlib.h>

void hanoi(unsigned, unsigned, unsigned);

static unsigned moves; /* we'll keep track of how many moves it takes */


/* Move a tower of n disks from origin peg to destination peg */
void hanoi(unsigned n, unsigned orig, unsigned dest)
{
   unsigned inter = 6 - orig - dest;  /* the intermediate  peg */
   moves++;

/* Our strategy here is to get to the bottom disk of a tower 
   of n disks by moving n-1 disks above it out of the way so
   we can move the bottom disk from the origin peg to the 
   destination peg, after which we need to move the n-1 disks
   from the intermedite peg to the destintion peg. If there is
   only 1 disk to move, we can move it immediately from origin
   to destination.

   Since we can move only one disk at a time, we'll have to move the
   n-1 disks using the same procedure called recursively.
*/   


   if(n == 1) 
      printf("Top disk on peg %u => peg %u\n", orig, dest);
   else {
      hanoi(n-1, orig, inter);
      printf("Top disk on peg %u => peg %u\n", orig, dest);
      hanoi(n-1, inter, dest);
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

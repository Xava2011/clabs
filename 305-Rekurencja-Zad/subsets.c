/*  
    Napisz funkcj� `ListSubsets' generuj�c� wszystkie
    mo�liwe podzbiory podanego zbioru, gdzie zbi�r
    sk�ada si� z liter podanych w postaci napisu.
    Na przyk�ad po wywo�aniu `ListSubsets("ABC")'
    na terminalu powinni�my otrzyma� (by� mo�e 
    w innej kolejno�ci):

       {ABC}   {BC}  
       {AB}    {B}
       {AC}    {C}
       {A}     {}
 */

#include <stdio.h>
#include <stdlib.h>
#include "strlib.h"

char napis[] = "ABC";

static void ListSubsets(string str);

int main() {
  ListSubsets(napis); 
  return EXIT_SUCCESS;
}

static void ListSubsets(string str) {
  printf("???\n");
}

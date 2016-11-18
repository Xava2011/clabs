/*  
   W komputerze, liczby ca�kowite s� reprezentowane w postaci
    ci�gu bit�w, z kt�rych ka�dy mo�e przyjmowa� warto��
    0 lub 1. Za pomoc� ci�gu bit�w d�ugo�ci N mo�na przedstawi� 
    2^N r�nych liczb ca�kowitych.
    Na przyk�ad trzy bity wystarczaj� do zapisania o�miu (2^3)
    liczb ca�kowitych:

      000 -> 0   100 -> 4
      001 -> 1   101 -> 5
      010 -> 2   110 -> 6
      011 -> 3   111 -> 7

   Napisa� funkcj� rekurencyjn� `GenerateBinaryCode(nBits)'
   wypisuj�c� wszystkie ci�gi bit�w d�ugo�ci `nBits'.
 */

#include <stdio.h>
#include <stdlib.h>
#include "strlib.h"

static void GenerateBinaryCode(int nBits);

int main() {
  GenerateBinaryCode(3); 
  return EXIT_SUCCESS;
}

static void GenerateBinaryCode(int nBits) {
  printf("???\n");
}

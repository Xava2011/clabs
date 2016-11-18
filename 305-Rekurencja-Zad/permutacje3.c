/*  
   Tym razem chcemy otrzyma� co� takiego:
      ListPermutations("AABB") => AABB
                                  ABAB
                                  ABBA
                                  BAAB
                                  BABA
                                  BBAA
   Teraz podany napis mo�e zawiera� powtarzaj�ce
   si� litery. Funkcja rekurencyjna nie powinna
   generowa� dodatkowych permutacji
 */

#include <stdio.h>
#include <stdlib.h>
#include "strlib.h"

char napis[] = "AABB";

static void ListPermutations(string str);

int main() {
  ListPermutations(napis); 
  return EXIT_SUCCESS;
}

static void ListPermutations(string str) {
  printf("???\n");
}

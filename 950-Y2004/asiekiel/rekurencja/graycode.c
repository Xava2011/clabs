/*  
 *  File: graycode.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:39:03 $
 *
    Liczby z przedzia�u [0..7], mo�emy ponumerowa� inaczej
    ni� w `binarycode.c'. Na przyk�ad w taki spos�b:

      000 -> 0   110 -> 4
      001 -> 1   111 -> 5
      011 -> 2   101 -> 6
      010 -> 3   100 -> 7
 
    Zauwa�my, �e przy takiej numeracji kolejne liczby
    r�ni� si� tylko na jednym bicie, np. reprezentacje
    bitowe liczb 3 i 4 r�ni� si� pierwszym bitem.
    Taki kodowanie liczb nazywamy kodowaniem Gray'a.
    Napisz funkcj� `GenerateGrayCode(nBits)' wypisuj�c�
    dla podanej liczby `nBits' kody Gray'a dla kolejnych
    liczb naturalnych od 0 do 2^N-1.
    Czy wiesz do czego takie kodowanie mo�e si� przyda�?
    UWAGA: jest wiele rozwi�za�.
 */

#include <stdio.h>
#include <stdlib.h>
#include "strlib.h"

static void GenerateGrayCode(int nBits);


int main() {
  GenerateGrayCode(4); 
  return EXIT_SUCCESS;
}

/* Co pierwsze dokleja� --- zero czy jedynk� */
typedef enum {
      FIRST_ZERO,
      FIRST_ONE
} ConcatFirst;

/* Je�li najpierw trzeba doklei�:
 *   zero -- do pierwszego ci�gu doklej zero i ka� doklei� znowu zero,
 *           do drugiego doklej jedynk� i ka� doklei� jedynk�
 *   jedynk� -- do pierwszego doklej jedynk� i ka� doklei� zero,
 *              do drugiego doklej zero i ka� doklei� jedynk�
 */
static void generate_codes(int nBits, string current, ConcatFirst what)
{
      if (nBits == 0)
            printf("%s\n", current);
      else if (what == FIRST_ZERO) {
            generate_codes(nBits - 1, Concat(current, "0"), FIRST_ZERO);
            generate_codes(nBits - 1, Concat(current, "1"), FIRST_ONE);
      } else if (what == FIRST_ONE) {
            generate_codes(nBits - 1, Concat(current, "1"), FIRST_ZERO);
            generate_codes(nBits - 1, Concat(current, "0"), FIRST_ONE);
      }
}

/* Zacznij od doklejania zera */
static void GenerateGrayCode(int nBits)
{
      generate_codes(nBits, "", FIRST_ZERO);
}


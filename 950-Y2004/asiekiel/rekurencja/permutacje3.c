/*  
 *  File: permutacje3.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:39:04 $
 *
   Wersja 3.
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
static void PermuteWithRepets(string prefix, string suffix);

int main() {
  ListPermutations(napis); 
  return EXIT_SUCCESS;
}

/* Funkcja sortuj�ca do qsorta */
int char_sort(const void* p1, const void* p2)
{
  const char c1 = *(const char*)p1, c2 = *(const char*)p2;
  if (c1 == c2)
    return 0;
  else if (c1 > c2)
    return 1;
  return -1;
}

static void ListPermutations(string str) {
  qsort(str, StringLength(str), 1, char_sort);
  PermuteWithRepets("", str);
}

/* D�ugo�� maksymalnego podci�gu w stringu 'str' rozpoczynaj�cego
 * si� od pozycji 'startpos' z�o�onego wy��cznie z liter str[startpos] */
static int count_same_letters(const char* str, int startpos)
{
      int i = startpos;
      char match = str[startpos];

      while (str[i] != '\0' && str[i] == match)
            ++i;
      return i - startpos;
}

/* Lekko zmodyfikowana procedura z przyk�adu 'permutacje2.c'.
 * Pomi� wywo�ania rekurencyjne dla powtarzaj�cych si� liter */
static void PermuteWithRepets(string prefix, string suffix) {
  int i, len;
  string newprefix, newsuffix;
  len=StringLength(suffix);
  if (len==0) 
    printf("%s\n",prefix);
  else {
    i = 0;
    while (i < len) {
      newprefix=Concat(prefix,SubString(suffix,i,i));
      newsuffix=Concat(SubString(suffix,0,i-1),SubString(suffix,i+1,len));
      PermuteWithRepets(newprefix,newsuffix);
      i += count_same_letters(suffix, i);
    }
  }
}

/* vim:sw=2
 */

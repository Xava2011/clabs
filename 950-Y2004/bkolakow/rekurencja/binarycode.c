/*  
 *  File: binarycode.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:40:27 $
 *
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
static void generator(string s, int nBits);
int main()
{
    GenerateBinaryCode(3);
    return EXIT_SUCCESS;
}

static void GenerateBinaryCode(int nBits)
{
    generator("", nBits);
}
static void generator(string s, int nBits)
{
    string temp;
    if (nBits == 0)
	printf("%s\n", s);
    else {
	temp = CopyString(s);
	s = Concat(s, "0");
	generator(s, nBits - 1);
	s = CopyString(temp);
	s = Concat(s, "1");
	generator(s, nBits - 1);
    }
}

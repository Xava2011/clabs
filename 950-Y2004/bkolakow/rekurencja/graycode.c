/*  
 *  File: graycode.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:40:27 $
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
static void generator(string s, int nBits, char l);

int main()
{
    GenerateGrayCode(3);
    return EXIT_SUCCESS;
}

static void GenerateGrayCode(int nBits)
{
    generator("", nBits, 0);
}

static void generator(string s, int nBits, char l)
{
    string temp;

    if (nBits == 0)
	printf("%s\n", s);
    else {
	if (l == 0) {
	    temp = CopyString(s);
	    s = Concat(s, "0");
	    generator(s, nBits - 1, 0);
	    s = CopyString(temp);
	    s = Concat(s, "1");
	    generator(s, nBits - 1, 1);
	} else {
	    temp = CopyString(s);
	    s = Concat(s, "1");
	    generator(s, nBits - 1, 0);
	    s = CopyString(temp);
	    s = Concat(s, "0");
	    generator(s, nBits - 1, 1);
	}
    }
}

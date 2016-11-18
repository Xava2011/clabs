/*  
 *  File: graycode.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:38:52 $
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

static void GenerateGrayCode(string s, int nBits, int nr);

int main() {
  GenerateGrayCode("",3,1); 
  printf("\n");
  return EXIT_SUCCESS;
}

static void GenerateGrayCode(string s,int nBits,int nr) 
{
	if (nBits==0) 
		printf("%s ",s);
	else
	{
		nBits--;
		if (nr==1)
		{
			GenerateGrayCode(Concat(s,"0"),nBits,1);
			GenerateGrayCode(Concat(s,"1"),nBits,2);
		}
		else 
		{
			GenerateGrayCode(Concat(s,"1"),nBits,1);
			GenerateGrayCode(Concat(s,"0"),nBits,2);
		}
	}

}

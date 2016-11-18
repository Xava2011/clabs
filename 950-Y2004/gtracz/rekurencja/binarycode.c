//Grzegorz Tracz
/*  
 *  File: binarycode.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:40:47 $
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

static void GenerateBinaryCode(int nBits);

int main() {
  GenerateBinaryCode(4); 
  return EXIT_SUCCESS;
}

void Generate(int nBits,int y,int *a, int *q){
  int *z,x;
  if(y==nBits){
    z=a;
    for (x=0;x<nBits;x++){
      printf("%d",*z);
      z++;
    }
    printf("\n");
  }else{
    *q=0;
    Generate(nBits,y+1,a,q+1);
    *q=1;
    Generate(nBits,y+1,a,q+1);
  }
}

static void GenerateBinaryCode(int nBits) {
int A[nBits+1];
 A[nBits+1]='\0';
 Generate(nBits,0,A,A);
}

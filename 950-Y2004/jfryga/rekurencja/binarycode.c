/*  
 *  File: binarycode.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:40:48 $
 *
    W komputerze, liczby ca�kowite s� reprezentowane w postaci
    ci�gu bit�w, z kt�rych ka�dy mo�e przyjmowa� warto��
    0 lub 1. Za pomoc� ci�gu bit�w d�ugo�ci N mo�na przedstawi� 
    2^N r�nych liczb ca�kowitych.
    Na przyk�ad trzy bity wystarczaj� do zapisania o�miu (2^3)
    liczb ca�kowitych:
asiekasiek
      000 -> 0   100 -> 4
      001 -> 1   101 -> 5
      010 -> 2   110 -> 6
      011 -> 3   111 -> 7

   Napisa� funkcj� rekurencyjn� `GeneratasiekeBinaryCode(nBits)'
   wypisuj�c� wszystkie ci�gi bit�w d�ugo�ci `nBits'.
 */


#include <stdio.h>
#include <stdlib.h>
/*#include "strlib.h"*/

static void GenerateBinaryCode(int nBits, int nBits2);
static void  int2bin(int i,int dl);

int main() {
  int ile;
  printf("\n ile bitow : ");
  scanf("%d",&ile);
  GenerateBinaryCode(ile,ile); 
  return EXIT_SUCCESS;
}

static void GenerateBinaryCode(int nBits, int nBits2) {

  int l;
  int high=2;
  int low=2;
  
  int pom=nBits;
  
  if(pom<=0) exit(1);
  if(pom>1){
      l = pom-1;
  for(;l!=0;l--){
    high*=2;
  }
  l=pom-2;
   for(;l!=0;l--){
    low*=2;
  }
    }

 if(pom==1){
   int2bin(1,nBits2);
   int2bin(0,nBits2);
}
  else {
      for(--high;high>=low;high--){
	int2bin(high,nBits2);  /* funkcja bierze liczbe dziesietna i wyswietla binarnie na okreslonej liczbie bitow */
      }                         
      GenerateBinaryCode(pom-1, nBits2);
   }
}



void int2bin(int i,int dl){  /* funkcja do wyswietlania liczby dziesietnej binarnie */

   int j,k=0;
  int tab[dl];

  for(j=0;j<dl;j++) { tab[j]=0;}  /* tutaj konwersja z dziesietnej na binarna */
   while(i!=0){
    tab[k]=i % 2;
    i/=2;
    k++;
  }
   for(j=dl-1;j>=0;j--){    printf("%d",tab[j]);  }  
   printf("\n"); 
}

//Grzegorz Tracz
/*  
 *  File: graycode.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:40:47 $
 *
    Problem podzia�u (ang. partition problem) polega na podaniu
    wszystkich podzbior�w danego zbioru liczb, kt�rych elementy 
    sumuj� si� podanej liczby. 
    Na przyk�ad, mo�emy wybra� dwa podzbiory zbioru {1, 3, 4, 5}
    kt�rych suma element�w wynosi 5: {1,4} i {5}.
    Zbi�r {1, 3, 4, 5} nie zawiera podzbioru, kt�rego suma 
    element�w wynosi 11.

    Napisa� funkcj� `NumberOfPartitions', kt�ra dla podanego
    zbioru i podanej liczby wyliczy ile zawiera on podzbior�w
    kt�rych suma element�w r�wna si� podanej liczbie.
    Na przyk�ad, dla podanego zbioru 
    NumberOfPartitions(sampleSet,4,5) wynosi 2.
    
    Deklaracje i definicje s� podane poni�ej.
 */

#include <stdio.h>
#include <stdlib.h>

int g=0;
static int NumberOfPartitions(int *str, int y, int target);

void drukuj(int *a,int *q, int y,int *str,int size,int target){
  int *z,x,h;
  z=a;
  h=0;
  for (x=0;x<y;x++){
    h=h+(*z);
    z++;
  }
  if (h==target)g++;
  for (x=y;x<size;x++){
     if (*str!='\0'){
      if (*q==*str);
      else{
	*q=*str;
	str++;
	*(q+1)='\0';
	drukuj(a,q+1,y+1,str,size,target);
      }
    }
  }
}

int sampleSet[] = {1, 3, 4, 5, 7};

int main() {
  int x,e,s;
  s=10;
  e=5;
  printf("\nLiczba podzialow zbioru {");
  for(x=0;x<e;x++)
    printf("%d, ",sampleSet[x]);
  printf("} sumujacych sie do %d to %d\n",s, NumberOfPartitions(sampleSet,e,s));
  return EXIT_SUCCESS;
}

static int NumberOfPartitions(int *str, int y, int target) {
  int A[y];
  A[y]='\0';
  drukuj(A,A,0,str,y,target);
  return g;
} 

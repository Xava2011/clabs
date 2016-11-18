/*  
 *  File: graycode.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:40:34 $
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

int sampleSet[] = {0, 1, 3, 4, 5};
int wynik;
int *p;

int NumberOfPartitions(int sampleSet[], int size, int target) {
  int i;
  
  for (i = size; i>=1; i--){
    if(sampleSet[i] == target)
      (*p)++;
    else if(sampleSet[i]<target)
      NumberOfPartitions(sampleSet, i-1, target-sampleSet[i]);
  }
  return *p;
}

int main() {
  int liczba;
  wynik = 0;
  p = &wynik;

  liczba = 4;

  printf("\nLiczba podzia��w zbioru {1,3,4,5} ");
  printf("sumuj�cych si� do %d to %d.\n\n", liczba, NumberOfPartitions(sampleSet,4,liczba));
  return EXIT_SUCCESS;
}


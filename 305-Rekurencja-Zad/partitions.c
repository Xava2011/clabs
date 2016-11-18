/*  
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
#include "strlib.h"

static int NumberOfPartitions(int sampleSet[], int size, int target);

int sampleSet[] = {1, 3, 4, 5};

int main() {
  printf("Liczba podzia��w zbioru {<wypisa� elementy>} sumuj�cych si� do %d to %d\n",
	 4, NumberOfPartitions(sampleSet,4,5));
  return EXIT_SUCCESS;
}

static int NumberOfPartitions(int sampleSet[], int size, int target) {
  return 2;
}

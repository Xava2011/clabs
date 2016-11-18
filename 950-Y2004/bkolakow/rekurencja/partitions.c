/*  
 *  File: graycode.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:40:27 $
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
#include "strlib.h"

static int NumberOfPartitions(int sampleSet[], int size, int target);
static void generator(int *findp, int n, int liczba, int i, int target,
		      int *tab);
int suma(int n, int liczba, int *tab);
static void zerowanie(int n, int liczba, int *tab);
static void drukuj(int *tab, int wielkosc_tab);

int sampleSet[] = { 1, 3, 4, 5 };

int main()
{
    printf("Liczba podzia��w zbioru {");
    drukuj(sampleSet, 4);	/* liczba element�w zbioru */
    printf("} sumuj�cych si� do %d to %d\n",
	   5, NumberOfPartitions(sampleSet, 4, 5));
    return EXIT_SUCCESS;
}

static int NumberOfPartitions(int sampleSet[], int size, int target)
{
    int find = 0, tab[size];
    if (target == suma(0, size - 1, sampleSet))
	find++;
    zerowanie(size - 1, size - 1, tab);
    generator(&find, size - 1, size - 1, 0, target, tab);
    return find;
}

static void generator(int *findp, int n, int liczba, int i, int target,
		      int *tab)
{
    if (n == 0);
    else {
	for (; i <= n; i++) {
	    tab[liczba - n] = sampleSet[liczba - n + i];
	    if (target == suma(n, liczba, tab))
		(*findp)++;
	    /*printf("{%s}\n",s); */
	    generator(findp, n - 1, liczba, i, target, tab);
	    zerowanie(n, liczba, tab);
	}
    }
}

int suma(int n, int liczba, int *tab)
{
    int sum = 0, i;
    for (i = 0; i <= (liczba - n); i++) {
	sum += tab[i];
	/*printf("%d\n",sum); */
    }
    return sum;
}

static void zerowanie(int n, int liczba, int *tab)
{
    int i;
    for (i = liczba; i <= (liczba - n); i--) {
	tab[i] = 0;
    }
}

static void drukuj(int *tab, int wielkosc_tab)
{
    int i;
    for (i = 0; i < wielkosc_tab; i++)
	printf((i != wielkosc_tab - 1) ? "%d, " : "%d", tab[i]);
}

/*  
 *  File: graycode.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:38:52 $
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
static void Subsets(int s[], int subset[], int k,int size, int size1, int target, int *p); 
static void PrintSub(int *subset, int size);
int sumEl(int *subset, int size1);

int sampleSet[] = {1, 3, 4, 5};

int main() {
	int i, size=4;
	int num;
	int target=5;
	num=NumberOfPartitions(sampleSet,size,target);
	printf("Liczba podzia��w zbioru {");
	for(i=0; i<size; i++)
		printf("%d ",sampleSet[i]);
	printf("} sumuj�cych si� do %d to %d\n",target,num); 
	return EXIT_SUCCESS;
}

static int NumberOfPartitions(int sampleSet[], int size, int target) 
{
	int p=0;
	int subset[size];
	Subsets(sampleSet,subset,0,size,0,target,&p);
	return p;
}

static void Subsets(int s[], int subset[], int k,int size,int size1, int target, int *p) 
{
	int i;
	
	if (sumEl(subset,size1)==target) 
	{
		(*p)++;
		PrintSub(subset,size1);
	}
	for(i=k; i<size; ++i)
	{
		subset[size1]=s[i];
		Subsets(s,subset,i+1,size,size1+1,target,p);		
	}
}

static void PrintSub(int *subset, int size1)
{
	int i;
	printf("{ ");
	for(i=0; i<size1; i++)
		printf("%d ",subset[i]);
	printf("}\n");
}

int sumEl(int *subset, int size1)
{
	int sum, i;
	for (i=0,sum=0; i<size1; i++)
		sum+=subset[i];
	return sum;
}

#ifndef INCLUDED__MAZE_H
#define INCLUDED__MAZE_H

#include <stdbool.h>
#include "mazelib.h"

/* Znajd� drog� do wyj�cia */
bool SolveMaze(pointT pt);

/* D�ugo�� najkr�tszej �cie�ki */
#define NoSolution 100000
int ShortestPathLength(pointT pt);

/* Tablica wszystkich kierunk�w */
extern directionT all_directions[];

#endif


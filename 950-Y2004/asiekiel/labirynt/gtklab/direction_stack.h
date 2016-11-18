#ifndef INCLUDED__DIRECTION_STACK_H
#define INCLUDED__DIRECTION_STACK_H

#include "mazelib.h"

/* Funkcje do obs�ugi stosu u�ywanego do �ledzenia rozpatrywanej
 * drogi w algorytmie wyszukiwania wyj�cia.
 * (musimy r�cznie symulowa� rekurencj�, bo funkcja szukaj�ca
 * drog� musi wyj��, aby mo�na by�o efektywnie akutalizowa� obraz)
 *
 * Na stosie znajduj� si� tr�jki (d, p, b), gdzie
 * d wyznacza kierunek dalszej w�dr�wki, p jest
 * ko�cowym punktem drogi, a warto�� logiczna b okre�la,
 * czy poszli�my ju� we wszystkich kierunkach tego punktu */

void ds_push(directionT dir, pointT pt, bool);
void ds_pop(void);
void ds_top(directionT* dir, pointT* pt, bool*);
bool ds_empty(void);
void ds_clear(void);
/* Ustaw warto�� kierunku na szczycie stosu */
void ds_set_dir_at_top(directionT dir);
void ds_set_last_d_at_top(bool ld);
void ds_print(void);

#endif


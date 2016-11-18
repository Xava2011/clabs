/* Jakub S�awi�ski (Slaughter House Entertainment Group)
 * plik nag��wkowy do funkcji rozwi�zuj�cych problemy labiryntowe
 * mw_maze.h
 */

#include "mw_lib.h"

#ifndef _JS_MW_MAZE_H
#define _JS_MW_MAZE_H

struct { /* struktura do wynajdowania najkr�tszej �cie�ki */
	int xsize, ysize;
	int** powierzchnia;
} wyniki;

/* tablica trzymaj�ca mo�liwe kierunki do przemieszczania si� */
extern kierunkiT tablica[];

int RozwiazLabirynt(punktT); /* rekurencyjne znajdowanie wyj�cia */
void RysujLabirynt(int, int, char); /* wyrysowuje labirynt */
void RysujSciezke(int, punktT*, int); /* wyrysowuje scie�k� */
void RysujInfo(int); /* wyrysowuje info */
int NajkrotszaSciezka(punktT); /* znajdowanie d�ugo�ci najkr�tszej �cie�ki */
punktT* ZnajdzSciezke(punktT); /* wynajduje kolejne punkty �cie�ki */

#endif

/*  
 *  File: minimax.c
 *
    Uniwersalne funkcje do ka�dej gry zaimplementowanej
    za pomoc� algorytmu minimax.
 */

#ifndef MINIMAX_INCLUDED
#define MINIMAX_INCLUDED

#include "othello.h"

/*  Funkcja ta znajduje najlepszy ruch dla gracza wykonuj�cego
    ruch. Parametr depth i sta�a MaxDepth u�ywana jest do ograniczenia
    g��boko�ci przeszukiwania (w "Othello" pe�na analiza nie jest 
    wykonywalna.) Funkcja zwraca najlepszy znaleziony ruch i zapisuje 
    w podanej zmiennej ca�kowitej jego ocen� lub (-1,-1) gdy gracz nie 
    ma ruchu i musi spasowa� */

moveT FindBestMove(stateT state, int depth, float *pRating);

/*  Funkcja ta wycenia pozycj� znajduj�c ocen� najlepszego
    ruchu w tej pozycji. */

float EvaluatePosition(stateT state, int depth);

/*  Funkcja opakowuj�ca funkcj� FindBestMove.  
    Tutaj wybierany jest ruch komputera. */

moveT ChooseComputerMove(stateT state);

#endif

/*  
 *  File: minimax.c
 *
 *  $Revision: 1.3 $
 *  $Date: 2004/01/06 20:19:52 $
 *
    Uniwersalne funkcje do ka�dej gry zaimplementowanej
    za pomoc� algorytmu minimax.
 */

#ifndef MINIMAX_INCLUDED
#define MINIMAX_INCLUDED

#include "kik.h"

/*  Funkcja ta znajduje najlepszy ruch dla gracza wykonuj�cego
    ruch. Parametr depth i sta�� MaxDepth u�ywamy do ograniczenia
    g��boko�ci przeszukiwania w grach, w kt�rych taka pe�na 
    analiza nie jest wykonywalna. Funkcja zwraca najlepszy
    znaleziony ruch i zapisuje w podanej zmiennej ca�kowitej
    jego ocen�. */

moveT FindBestMove(stateT state, int depth, int *pRating);

/*  Funkcja ta wycenia pozycj� znajduj�c ocen� najlepszego
    ruchu w tej pozycji. */

int EvaluatePosition(stateT state, int depth);

/*  Funkcja opakowuj�ca funkcj� FindBestMove.  
    Tutaj wybierany jest ruch komputera. */

moveT ChooseComputerMove(stateT state);

#endif

/*  
 *  File: minimax.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:39:46 $
 *
    Uniwersalne funkcje do ka�dej gry zaimplementowanej
    za pomoc� algorytmu minimax.
 */

#ifndef MINIMAX_INCLUDED
#define MINIMAX_INCLUDED

#include "nim.h"

/*  Funkcja ta znajduje najlepszy ruch dla gracza wykonuj�cego
    ruch. Parametr depth i sta�� MaxDepth u�ywamy do ograniczenia
    g��boko�ci przeszukiwania w grach, w kt�rych taka pe�na 
    analiza nie jest wykonywalna. Funkcja zwraca najlepszy
    znaleziony ruch i zapisuje w podanej zmiennej ca�kowitej
    jego ocen�. */

moveT FindBestMove(int st_tmp[], int n, int r);

//Zrezygnowa�em z implementacji funkcji 
//EvaluatePosition, z powodu prostoty operacji jakie mialaby
//ona u mnie wykonywa�. (wyb�r 0 lub 1)
//Ruch mo�e by� u mnie oceniony na 0 lub 1,
//(ruch wygrywaj�cy lub przegrywaj�cy)
//Wyb�r ruchu dokonuje si� wewn�trz funkcji
//opisanych poni�ej.

//moveT EvaluatePosition(stateT state, int depth);


moveT ChooseComputerMove(void);

int IsBadPosition(int st_tmp[]);

#endif

#ifndef INCLUDED__MINIMAX_H
#define INCLUDED__MINIMAX_H

#include "eval-pos.h"
#include "game-repr.h"
#include "game-rules.h"
#include "config.h"

using namespace KIK;
      
// Og�lna funkcja FindBestMove zwracaj�ca najlepszy ruch, kt�ry mo�e wykona�
// aktualny gracz (gracz, kt�ry musi wykona� nast�pny ruch).
//
// Funkcja ta jest niezale�na od konkretnej reprezentacji gry -- wystarczy
// napisa� w nowej przestrzeni nazw implementacj� regu� gry i okre�li�
// reprezentacj� gry, by mo� j� zastosowa� do dowolnej gry dwuosobowej

Move FindBestMove(State& state);

// Po ka�dym wywo�aniu FindBestMove zmienna ta zawiera liczb� sytuacji na planszy gry,
// kt�re przeanalizowano
extern int evaluated_positions;

#endif


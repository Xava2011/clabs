/*  
 *  File: minimax.c
 *
 *  $Revision: 1.3 $
 *  $Date: 2004/01/06 20:19:52 $
 *
    Uniwersalne funkcje do ka�dej gry zaimplementowanej
    za pomoc� algorytmu minimax.
 */

#include "minimax.h"

/*
 *  Funkcja prywatna.
 */

/*  Funkcja zwracaj�ca ocen� pozycji bez dalszego przegl�dania 
    drzewa gry. Chocia� z jednej strony funkcja ta powtarza 
    sporo oblicze� funkcji GameOver zmniejszaj�c w ten spos�b
    nieco szybko�� dzia�ania programu, to z drugiej strony
    u�atwia ona zrozumienie tego programu. */

static int EvaluateStaticPosition(stateT state);

/*  Funkcja generuj�ca list� poprawnych ruch�w mo�liwych do
    wykonania z podanej pozycji. Lista ruch�w zwracana jest
    w tablicy moveArray podanej i zaalokowanej przez
    klienta. Funkcja zwraca liczb� poprawnych ruch�w. */

static int GenerateMoveList(stateT state, moveT moveArray[]);

/*
 *  Funkcje ekportowane.
 */

moveT FindBestMove(stateT state, int depth, int *pRating)
{
   moveT moveArray[MaxMoves], move, bestMove;
   int i, nMoves, rating, minRating;

   nMoves=GenerateMoveList(state,moveArray);
   if (nMoves==0)
      Error("Nie mo�na wykona� ruchu");
   minRating=WinningPosition+1;
   for (i=0; i<nMoves && minRating!=LosingPosition; i++) {
      move=moveArray[i];
      MakeMove(state,move);
      rating=EvaluatePosition(state,depth+1);
      if (rating<minRating) {
         bestMove=move;
         minRating=rating;
      }
      RetractMove(state,move);
   }
   *pRating=-minRating;
   return bestMove;
}

int EvaluatePosition(stateT state, int depth)
{
  int rating;

  if (GameIsOver(state) || depth>=MaxDepth) {
    return EvaluateStaticPosition(state);
  }
  (void) FindBestMove(state,depth,&rating);
  return rating;
}

static int GenerateMoveList(stateT state, moveT moveArray[])
{
  int i, nMoves;
  nMoves=0;
  for (i=0; i<=9; i++) {
    if (state->board[i]==' ') {
      moveArray[nMoves++]=(moveT) i;
    }
  }
  return nMoves;
}

moveT ChooseComputerMove(stateT state)
{
  int rating;
  printf("M�j ruch.\n");
  return FindBestMove(state,0,&rating);
}


static int EvaluateStaticPosition(stateT state)
{
  if (CheckForWin(state,state->whoseTurn)) {
    return WinningPosition;
  }
  if (CheckForWin(state,Opponent(state->whoseTurn))) {
    return LosingPosition;
  }
  return NeutralPosition;
}

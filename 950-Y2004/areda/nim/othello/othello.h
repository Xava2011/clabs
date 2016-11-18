#ifndef OTHELLO_INCLUDED
#define OTHELLO_INCLUDED

#include "genlib.h"

/*  Sta�e okre�laj�ce system oceniania pozycji w grze.*/ 

#define WinningPosition  1000
#define NeutralPosition  0
#define LosingPosition  (-WinningPosition)

/*  Typ umo�liwiaj�cy rozr�nienie graczy. */

typedef enum { Human, Computer } playerT;

/*   Typ umo�liwiaj�cy rozr�nienie kierunk�w */

typedef enum { North, East, South, West, NE, ES, SW, WN} directionT;

/*  Typ moveT umo�liwia zapami�tanie pojedynczego
    ruchu w grze. */

typedef struct {
  int x,y;
} moveT;

/* Stan gru zapami�tany jest w strukturze.
 * board - tablica wska�nik�w, zapami�tuje plansz�
 * whoseTurn - przechowuje informacj� o tym czyj jest ruch
 * turnsTaken - zawiera ilo�� wykonanych ruch�w 
 * (w "Othello" ka�dy ruch oznacza zaj�cie jednego pola na planszy) */ 

typedef struct {
  char board[10][11];
  playerT whoseTurn;
  int turnsTaken;
} *stateT;

/*  Sta�a ta okre�la maksymaln� liczba ruch�w.
    Korzystamy z niej alokuj�c, w danej pozycji, pami�� na 
    tablic� dopuszczalnych ruch�w. */

#define MaxMoves 60

/*  Sta�a ta okre�la maksymaln� g��boko�� rekurencji
    w poszukiwaniu najlepszego ruchu. */

#define MaxDepth 4 

/*  Sta�a ta wskazuje, kto ma pierwszy ruch. */

#define FirstPlayer Computer

/*  T� funkcj� zaczynamy now� gr�. Zwraca ona stan pocz�tkowy
    gry. */

stateT NewGame(void);

/*  Funkcja zmienia stan gry wykonuj�c podany ruch. */

void MakeMove(stateT state, moveT move);

/*  Funkcja zwraca TRUE je�li state wskazuje na koniec gry. */

bool GameIsOver(stateT state);

/*  Funkcja zwracaj�ca w podanym stanie czyj jest ruch. */

playerT WhoseTurn(stateT state);

/*  Funkcja zwracaj�ca znak na planszy gry w miejscu move */

char BoardXY(stateT state, moveT move);

/*  Funkcja zmienia stan gry ,,odwo�uj�c'' podany ruch. */

void RetractMove(stateT state, char **boardCopy);

/*  Funkcja zwraca TRUE je�li podany gracz wygra� gr�. */

bool CheckForWin(stateT state, playerT player);

/*  Funkcja zwraca warto�� wskazuj�ca czyj jest nast�pny ruch. */

playerT Opponent(playerT player);

/*  Funkcja prze��czaj�ca gracza */

void SwitchToOpponent(stateT state);

/*  Funkcja zwracaj�ca pozycj� s�siedniego punktu w kierunku dir */

moveT AdjacentPoint(moveT pt, directionT dir);

/*  Funkcja zwraca TRUE je�li mo�na wykona� podany ruch */

bool MoveIsLegal(moveT move, stateT state);

/*  Funkcja zwraca TRUE gdy dany gracz nie mo�e wykona� �adnego ruchu */

bool NoLegalMoves(stateT state);

/*  Funkcja zwracaj�ca znak umieszczany na planszy 
    przez gracza wykonuj�cego ruch. */

char PlayerMark(playerT player);

/*  Funkcja kopiuj�ca tablic� z zapisem stanu gry - 
 *  wykorzystywana przy powrotach */
	
void CopyBoard(char **boardCopy, stateT state);

#endif

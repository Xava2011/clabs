/*  
 *  File: kik.h
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:39:05 $
 *
    Interfejs do gry w k�ko i krzy�yk.
 */

#ifndef KIK_INCLUDED
#define KIK_INCLUDED


#include "genlib.h"



/*  Sta�a ta okre�la maksymaln� g��boko�� rekurencji
    w poszukiwaniu najlepszego ruchu.
    W tej wersji programu przeprowadzamy analiz�
    wszystkich ruch�w. */

#define MaxDepth 4

/*  Rozmiar jednego boku planszy */

#define BoardSize 5

/*  Minimalna ilo�� punkt�w potrzebna do wygranej */

#define  WinnerResult 4

/*  Sta�e okre�laj�ce system oceniania pozycji w grze. 
    Sta�e WinningPosition i LosingPosition s� przeciwnych
    znak�w. Ich warto�ci maj� okre�la� odpowiednio pewn�
    wygran� lub przegran�. W grze w kt�rej analizowane
    s� wszystkie mo�liwe ruchy, nie s� potrzebne �adne
    inne po�rednie oceny. Je�li taka analiza nie jest
    mo�liwa, to funkcja EvaluatePosition zwraca liczb�
    ca�kowit� mi�dzy tymi dwoma skrajnymi warto�ciami. */

#define WinningPosition  1000
#define NeutralPosition  0
#define LosingPosition  (-WinningPosition)

/*  Typ umo�liwiaj�cy rozr�nienie graczy. */

typedef enum { Human, Computer } playerT;

/*  Typ moveT powinien umo�liwi� zapami�tanie pojedynczego
    ruchu w grze. 
    Dla gry w k�ko i krzy�yk, wystarczy zapami�ta� 
    pozycj� w kt�rej stawiamy `x' b�d� `o'. */

typedef int moveT;


/*  Sta�a ta okre�la maksymaln� liczba ruch�w.
    Korzystamy z niej alokuj�c, w danej pozycji, pami�� na 
    tablic� dopuszczalnych ruch�w. */

#define MaxMoves  BoardSize*BoardSize


/*  Stan ka�dej gry zapami�tujemy w strukturze. Dla gry w k�ko
    i krzy�yk g��wnym elementem struktury jest tablica znakowa
    w kt�rej umieszczamy `x', `o', ` ', oznaczaj�c w ten spos�b
    ruchy wykonane przez pierwszego i drugiego gracza oraz wolne
    miejsca. Chocia� tablica do gry jest dwuwymiarowa, to
    u�ywamy tablicy jednowymiarowej, tak aby indeksy odpowiada�y
    numerom u�ywanym przez graczy:

         1 | 2 | 3
        ---|---|---
         4 | 5 | 6
        ---|---|---
         7 | 8 | 9

    Zwr��my uwage, �e element o indeksie 0 nie jest u�ywany.
    Dodatkowo w strukturze zapami�tujemy, kto nast�pny ma wykona�
    ruch. Dla gry w k�ko i krzy�yk wygodnie jest dodatkowo 
    pami�ta� liczb� wykonanych ruch�w. Umo�liwia to szybkie
    sprawdzenie, czy s� jeszcze wolne miejsca.
*/

typedef struct {
  char board[MaxMoves+1];
  playerT whoseTurn;
  int turnsTaken;
} *stateT;


/*  Sta�a ta wskazuje, kto ma pierwszy ruch. */

#define FirstPlayer Computer

/*  T� funkcj� zaczynamy now� gr�. Zwraca ona stan pocz�tkowy
    gry. */

stateT NewGame(void);

/*  Funkcja zmienia stan gry wykonuj�c podany ruch. */

void MakeMove(stateT state, moveT move);

/*  Funkcja zwraca TRUE je�li state wskazuje na koniec gry. */

int GameIsOver(stateT state);

/*  Funkcja zwracaj�ca w podanym stanie czyj jest ruch. */

playerT WhoseTurn(stateT state);

/*  Funkcja zmienia stan gry ,,odwo�uj�c'' podany ruch. */

void RetractMove(stateT state, moveT move);

/*  Funkcja zwraca TRUE je�li podany gracz wygra� gr�. */

int CheckForWin(stateT state, playerT player);

/*  Funkcja zwraca warto�� wskazuj�ca czyj jest nast�pny ruch. */

playerT Opponent(playerT player);

#endif

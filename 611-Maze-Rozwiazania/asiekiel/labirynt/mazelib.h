/*  File: mazelib.h
 *
    Interfejs zawieraj�cy funkcje u�atwiaj�ce rozwi�zywanie labirynt�w.
 */


#ifndef mazelib_included
#define mazelib_included

#include "genlib.h"

/* W zmiennych typu `poinT' przechowujemy wsp�rz�dne punkt�w na p�aszczy�nie. */

typedef struct {
  int x, y;
} pointT;

/* Typ `directionT' reprezentuje kierunki w kt�rych mo�na porusza� si� po labiryncie. */

typedef enum { North, East, South, West} directionT;
    
/* Funkcja czytaj�ca labirynt z pliku o podanej nazwie.
   Labirynt jest zapami�tywany w strukturze danych zarz�dzanej przez funkcje
   tego modu�u. Sama struktura danych powinna by� zdefiniowana w pliku `mazelib.c'.

   Oto przyk�adowy labirynt (punkt w lewym g�rnym rogu powinien mie�
   wsp�rz�dne (0,0), a `S' wskazuje pozycj� pocz�tkow�):

          ###################
          # #       #     # #
          # ### ### # ### # #
          #     # # # #     #
          ####### # # ##### #
          #    S  # #   #   #
          # ##### # ### # ###
          # #   #   #   #   #
          # # # ##### ##### #
          #   # #     #   # #
          ##### # ##### # # #
          #     #     # #   #
          # ####### # ##### #
          # #     # #     # #
          # # # # ### ### # #
          # # # #   # #   # #
          # ### ### ### ### #
          #     #       #    
          ###################
 */   

void ReadMazeMap(string filename);

/* Funkcja zwraca wsp�rz�dne punktu pocz�tkowego, z kt�rego mamy 
   znale�� drog� do wyj�cia. */

pointT  GetStartPosition(void);

/* Funkcja zwraca TRUE je�li podany punkt jest poza labiryntem. */

bool OutsideMaze(pointT pt);


/* Funkcja zwraca TRUE, je�li w podanym kierunku `dir' w pozycji `pt'
   jest �ciana. */

bool WallExists(pointT pt, directionT dir);

/* Poni�sze funkcje zacznaczaj�, odznaczaj� podany punkt
   oraz sprawdzaj� czy punkt jest zaznaczony. */

void MarkSquare(pointT pt);
void UnmarkSquare(pointT pt);
bool IsMarked(pointT pt);

/* Funkcja zwraca wsp�rz�dne punktu o jeden krok dalej od podanego punktu `pt'
   w kierunku `dir'. */         
pointT AdjacentPoint(pointT pt, directionT dir);

#endif

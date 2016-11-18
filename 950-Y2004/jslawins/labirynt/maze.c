
#include <stdlib.h>
#include "mazelib.h"

#define	NoSolution	1000000

/* Funkcja `SolveMaze(pt)' pr�buje znale�� drog� do wyj�cia 
   z labiryntu z podanego punktu `pt'. Funkcja zwraca TRUE 
   je�li jest taka droga, a FALSE w przeciwnym wypadku.
   Funkcja korzysta z rekurencji do rozwi�zania podlabirynt�w
   powstaj�cych przez zaznaczenie bie��cego punktu 
   i przej�cie o jeden krok dalej niezablokowanym przej�ciem. */

static bool SolveMaze(pointT pt);

/* !!! */ 

directionT tablica[] = {North, East, South, West};
extern pointT PunktObok(pointT pt, directionT dir); /* jednak si� tutaj przyda */

/* Funkcja `Rysuj(znaczek)' wyrysowuje na ekranie labirynt.
 * Oznaczaj�c znaczkiem punkt startowy
 */

void Rysuj(char znaczek); /* do rysowania wykresu labiryntu */

/* Funkcja `ShortestPathLength(pt)' pr�buje znale�� d�ugo�� najkr�tszej
 * �cie�ki prowadz�cej z punktu pt do wyj�cia
 */

int ShortestPathLength(pointT pt); /* zadanie 2 */

/* Funkcja `NajkrotszaDlugoscSciezki(pt)' rekurencyjnie wyszukuje
 * najkr�tsz� d�ugo�� �cie�ki
 */

int NajkrotszaDlugoscSciezki(pointT pt); /* zadanie 2 */

/* Obiekt wyniki typu struktury s�u��cy do wynajdowania najkr�tszej �cie�ki */

static struct {
	int xsize, ysize;
	int** powierzchnia;
} wyniki;

/* Funkcja `FindPath(pt, path[], pathSize)' pr�buje znale�� najkr�tsz� �cie�ke z punktu pt do wyj�cia - kolejne punkty s� zapisywane w tablicy path (je�eli �cie�ka jest d�u�sza ni� pathSize - tylko pathSize punkt�w jest zapisywanych lecz zwracana jest poprawna d�ugo�� �cie�ki
 */

#define	MaxPath	100 /* �cie�ki o takiej max d�. b�dziemy szuka� */
int FindPath(pointT pt, pointT path[], int pathSize);

/* !!! */

string MazeFile = "labirynt.txt";  /* nazwa pliku z labiryntem */

int main() {
	int i, len; 
	pointT path[MaxPath]; /* tablica dla zadania 3 */
	/* zadanie 1 */
  ReadMazeMap(MazeFile);
    printf("Wczytany labirynt:\n\n");
    Rysuj('S');
  if (SolveMaze(GetStartPosition())) {
    printf("Zaznaczone kwadraty pokazuj� drog� do wyj�cia z labiryntu.\n\n");
    Rysuj('S');
  } else {
    printf("Z podanego punktu brak wyj�cia z labiryntu.\n\n");
  }
  	/* zadanie 2 */
  len = ShortestPathLength(GetStartPosition());
  if (len != NoSolution) {
	  printf("\nD�ugo�� najkr�tszej �cie�ki to %d\n\n", len);
  }
  else {
	  printf("Najkr�tsza �cie�ka nie istnieje.\n\n");
  }
  	/* zadanie 3 */
  len = FindPath(GetStartPosition(), path, MaxPath);
  if (len==0)
	  printf("Nie ma wyj�cia z labiryntu.\n\n");
  else {
	  printf("�cie�ka prowadz�ca do wyj�cia:\n");
	  for (i=0; i<((MaxPath < len)?MaxPath:len); ++i)
		  printf("->(%d,%d) ", path[i].x, path[i].y);
	  if (MaxPath < len)
		  printf(" ...");
	  printf("\n\n");
  }
  return EXIT_SUCCESS;
}

/* !!! */ /* Implementacje funkcji do zada� */ /* !!! */

bool SolveMaze(pointT pt) {
	int i;
	if (OutsideMaze(pt))
		return TRUE;
	if (IsMarked(pt))
		return FALSE;
	MarkSquare(pt);

	for (i = 0; i < 4; ++i) {
		if (!WallExists(pt, tablica[i]))
			if (SolveMaze(PunktObok(pt, tablica[i])))
				return TRUE;
	}
	
	UnmarkSquare(pt);
  return FALSE;
}

/* !!! */

int
ShortestPathLength(pointT pt)
{
	int min, i, j;
	pointT iterator; /* dla znalezienia rozmiaru labiryntu */
  	ReadMazeMap(MazeFile);

	if (wyniki.powierzchnia != NULL) { /* dealokowanie poprzedniej struktury*/
		for (i = 0; i < wyniki.xsize; ++i) {
			free(wyniki.powierzchnia[i]);
		}
		free(wyniki.powierzchnia);
	}
	
	iterator.x = 0;
	iterator.y = 0;
	
	while (TRUE) { /* znalezienie rozmiaru x */
		if (OutsideMaze(iterator)) {
			break;
		}
		iterator.x++;
	}
	wyniki.xsize = iterator.x;
	iterator.x = 0;
	
	while (TRUE) { /* znalezienie rozmiaru y */
		if (OutsideMaze(iterator)) {
			break;
		}
		iterator.y++;
	}

	wyniki.ysize = iterator.y;

	/* alokowanie struktury wyliczaj�cej wynik */
	wyniki.powierzchnia = calloc(1, wyniki.xsize * sizeof(int));
	for (i = 0; i < wyniki.xsize; ++i) {
		wyniki.powierzchnia[i] = calloc(1, wyniki.ysize * sizeof(int));
		for (j = 0; j < wyniki.ysize; ++j) { /* by p�niej �atwo update'owa� struktur� */
			wyniki.powierzchnia[i][j] = NoSolution;
		}
	}

	wyniki.powierzchnia[GetStartPosition().x][GetStartPosition().y] = 0;

	min = NajkrotszaDlugoscSciezki(pt);
	if (min) {
		return min+1; /* zaczynamy na wyj�ciu - �cie�ka ma d�. 1 */
	}
	return NoSolution;
}

int
NajkrotszaDlugoscSciezki(pointT pt)
{
	int i, k, flaga;
	pointT iterator;

	flaga = 0; /* oznacza brak zmian w strukturze */

	/* update struktury */
	iterator.x = 0;
	iterator.y = 0;
while (TRUE) { /* iteracja po y */
  if (OutsideMaze(iterator)) {
    break;
  }
  while (TRUE) { /* iteracja po x */
    if (OutsideMaze(iterator)) {
      iterator.x = 0;
      break;
    }
    for (i = 0; i < 4; ++i) {
      if (!WallExists(iterator, tablica[i])) {
	      if (OutsideMaze(PunktObok(iterator, tablica[i]))) {
		      continue; /* omijamy ten punkt */
	      }
	      iterator.x--; /* by rozpatrywa� bie��cy punkt */
	      if (WallExists(iterator, East)) {
		      iterator.x++; /* powr�t do wsp�rz�dnych */
		      continue; /* no i omini�cie tego punktu */
	      }
	      iterator.x++; /* powr�t do normalnych wsp�rz�dnych */
	      if (OutsideMaze(iterator)) {
		      continue; /* omijamy ten punkt */
	      }
        k = wyniki.powierzchnia[PunktObok(iterator, tablica[i]).x]
			[PunktObok(iterator, tablica[i]).y] + 1;
	if (k < wyniki.powierzchnia[iterator.x][iterator.y]) {
		wyniki.powierzchnia[iterator.x][iterator.y] = k;
		flaga = 1;
	}
      }
      else {
      }
    }
    iterator.x++;
  }
  iterator.y++;
} /* koniec update'u struktury */

	if (flaga) { /* je�eli by� update struktury */
		return NajkrotszaDlugoscSciezki(pt);
	}

	/* je�eli nie by�o update'u struktury -> odleg�o�ci od startu s� ju� dobre, wi�c trzeba wyszuka� teraz miejsca, sk�d jest wyj�cie, a jednocze�nie jest tam najmniejsza odleg�o�� od pocz�tku - flaga b�dzie trzyma� najmniejsz� odleg�o�� */
	iterator.x = 0;
	iterator.y = 0;
	flaga = NoSolution;
	for (i = 0; i < 4; ++i) {
		if (i==0) {iterator.x=0;iterator.y=wyniki.ysize-1;}
		if (i==1) {iterator.x=0;iterator.y=0;}
		if (i==2) {iterator.x=wyniki.xsize-1;iterator.y=0;}
		if (i==3) {iterator.x=wyniki.xsize-1;iterator.y=wyniki.ysize-1;}
	  while (TRUE) {
	    if (OutsideMaze(iterator)) {
	      break;
	    }
	    flaga = (wyniki.powierzchnia[iterator.x][iterator.y] < flaga)
			? wyniki.powierzchnia[iterator.x][iterator.y] : flaga;
	    iterator = PunktObok(iterator, tablica[i]);
	  }
	}
	if (flaga != NoSolution) {
		return flaga;
	}
	else {
		return 0;
	}
}

int
FindPath(pointT pt, pointT path[], int pathSize)
{
	int i, len, ilosc;
	pointT iterator;
  len = ShortestPathLength(GetStartPosition());
  if (len != NoSolution) {
	  ilosc = len; /* ilosc wskazuje na ilo�� punkt�w w �cie�ce */
	iterator.x = 0;
	iterator.y = 0;
	for (i = 0; i < 4; ++i) { /* szukanie wyj�cia */
		if (i==0) {iterator.x=0;iterator.y=wyniki.ysize-1;}
		if (i==1) {iterator.x=0;iterator.y=0;}
		if (i==2) {iterator.x=wyniki.xsize-1;iterator.y=0;}
		if (i==3) {iterator.x=wyniki.xsize-1;iterator.y=wyniki.ysize-1;}
	  while (TRUE) {
	    if (OutsideMaze(iterator)) {
	      break;
	    }
	    if (wyniki.powierzchnia[iterator.x][iterator.y] == len-1) { /* znaleziono wyj�cie */
		    i = 4; /* wyj�cie z p�tli for */
		    break; /* wyj�cie z p�tli while */
	    }
	    iterator = PunktObok(iterator, tablica[i]);
	  }
	} /* koniec szukania wyj�cia */

	/* iterator wskazuje teraz na wyj�cie - trzeba cofa� si� wzd�u� �cie�ki i je�eli pozwala na to wielko�� tablicy path - wpisywa� kolejne pola do tej tablicy */
	do {
		if (ilosc < pathSize) {
			path[ilosc] = iterator;
		}
		for (i = 0; i < 4; ++i) {
			if (!OutsideMaze(PunktObok(iterator, tablica[i]))) {
		  if ((wyniki.powierzchnia[PunktObok(iterator, tablica[i]).x]
			  [PunktObok(iterator, tablica[i]).y]) == ilosc - 1) {
			  iterator = PunktObok(iterator, tablica[i]);
			  break;
		  }
			}
		}
		ilosc--; 
	} while (ilosc >= 0);

  }
  else {
	  return 0;
  }
  return len;
}

void
Rysuj(char znaczek)
{
	pointT iterator;
    iterator.x = 0;
    iterator.y = 0;
    while (TRUE) { /* po y'ach iteracja */
	    if (OutsideMaze(iterator)) {
		    break;
	    }
	    while (TRUE) { /* po x'ach iteracja */
		    if (OutsideMaze(iterator)) {
			    printf("\n");
			    iterator.x = 0;
			    break;
		    }
		    iterator.x--;
		    if (WallExists(iterator, East)) {
			    printf("#");
			    iterator.x++;
			    iterator.x++;
			    continue;
		    }
		    iterator.x++;
		    if ((iterator.x == GetStartPosition().x) && (iterator.y == GetStartPosition().y)) {
			    putchar(znaczek);
		    }
		    else if (IsMarked(iterator) == TRUE) {
			    printf("x");
		    }
		    else {
			    printf(" ");
		    }
		    iterator.x++;
	    }
	    iterator.y++;
    }
}
/* !!! */

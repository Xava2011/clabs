#include <stdlib.h>
#include "mazelib.h"

/* Funkcja `SolveMaze(pt)' pr�buje znale�� drog� do wyj�cia 
   z labiryntu z podanego punktu `pt'. Funkcja zwraca TRUE 
   je�li jest taka droga, a FALSE w przeciwnym wypadku.
   Funkcja korzysta z rekurencji do rozwi�zania podlabirynt�w
   powstaj�cych przez zaznaczenie bie��cego punktu 
   i przej�cie o jeden krok dalej niezablokowanym przej�ciem. */

static bool SolveMaze(pointT pt);

/* Zapisz wsp�rz�dne punkt�w prowadz�cych do wyj�cia */
int FindPath(pointT pt, pointT path[], int pathSize);

/* D�ugo�� najkr�tszej �cie�ki */
int ShortestPathLength(pointT pt);

string MazeFile = "labirynt.txt";  /* nazwa pliku z labiryntem */

/* Pomocnicza tablica z wszystkimi kierunkami */
static directionT all_directions[] = { North, East, South, West };

/* Przyk�ad wykorzystania funkcji FindPath */
int main()
{
  pointT path[100000];
  int i, len;

  ReadMazeMap(MazeFile);
  len=FindPath(GetStartPosition(),path,100000);
  if (len==0) 
     printf("Nie ma wyj�cia z labiryntu.");
  else {
     printf("�cie�ka prowadz�ca do wyj�cia:\n");
     for (i=0; i<len; i++)
        printf("\t(%d,%d)\n",path[i].x,path[i].y);
  }
  return 0;
}

/* Przet�umaczenie pseudokodu z README.maze na C */
bool SolveMaze(pointT pt) {
      int i;
      
      if (OutsideMaze(pt))
            return TRUE;
      if (IsMarked(pt))
            return FALSE;
      MarkSquare(pt);
      for (i = 0; i < 4; ++i)
            if (!WallExists(pt, all_directions[i]))
                  if (SolveMaze(AdjacentPoint(pt, all_directions[i])))
                      return TRUE;
      UnmarkSquare(pt);
      return FALSE;
}

/* Sta�a symbolizuj�ca niesko�czon� d�ugo�� �cie�ki */
#define NoSolution 100000

/* Funkcja znajduje d�ugo�� najkr�tszej �cie�ki od punktu 'pt'
 * do wyj�cia. 'cur_length' jest d�ugo�ci� dotychczas przebytej drogi.
 * 
 * Je�eli wyszli�my z labiryntu, to znale�li�my �cie�k� o d�ugo�ci
 * 'cur_length'. Je�eli weszli�my na zaznaczone pole, to musimy
 * w tym miejscu zako�czy� poszukiwania i zasygnalizowa� brak drogi
 * wyj�ciowej.
 * Je�eli nie zasz�y powy�sze przypadki, to zaznaczamy aktualne pole.
 * Nast�pnie dla ka�dego kierunku 'k' obliczamy d�ugo�� �cie�ki dla
 * punktu 'pt' przesuni�tego w kierunku 'k' (o ile w punkcie tym nie ma
 * �ciany) i zwracamy najmniejsz� z tych warto�ci */
static int ShortestPathFinder(pointT pt, int cur_length) {
  int i;
  int min = NoSolution;
  int solution;

  if (OutsideMaze(pt))
    return cur_length;
  if (IsMarked(pt))
    return NoSolution;
  MarkSquare(pt);
  for (i = 0; i < 4; ++i)
    if (!WallExists(pt, all_directions[i])) {
      solution = ShortestPathFinder(AdjacentPoint(pt, all_directions[i]), cur_length + 1);
      if (solution < min)
        min = solution;
    }
  UnmarkSquare(pt);
  return min;
}

/* Opakowanie ShortestPathFinder */
int ShortestPathLength(pointT pt) {
      return ShortestPathFinder(pt, 0);
}

/* Funkcja dzia�a podobnie, jak SolveMaze. Przy wyszukiwaniu �cie�ki
 * zapisuje do tablicy 'path' wsp�rz�dne odwiedzanych p�l.  'current'
 * jest aktualn� d�ugo�ci� rozpatrywanej �cie�ki.
 *
 * Musimy uwa�a� na ewentualne przepe�nienie tablicy.
 *
 * Gdy znajdziemy wyj�cie, funkcja zwraca warto�� niezerow� i nast�puje
 * powr�t z wywo�a� rekurencyjnych */
static int PathFinder(pointT pt, pointT path[], int pathSize, int current) {
  int i;
  int pathlen;
  
  if (current >= pathSize)
    return 0;
  path[current] = pt;
  if (OutsideMaze(pt))
    return current;
  if (IsMarked(pt))
    return 0;
  MarkSquare(pt);
  for (i = 0; i < 4; ++i)
    if (!WallExists(pt, all_directions[i])) {
      pathlen = PathFinder(AdjacentPoint(pt, all_directions[i]), path, pathSize, current + 1);
      if (pathlen > 0)
        return pathlen;
    }
  return 0;
}

/* Opakowanie poprzedniej funkcji */
int FindPath(pointT pt, pointT path[], int pathSize) {
  return PathFinder(pt, path, pathSize, 0);
}

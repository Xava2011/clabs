/* Jakub S�awi�ski (Slaughter House Entertainment Group)
 * plik nag��wkowy do funkcji operuj�cych na labiryntach
 * mw_lib.h
 */

#ifndef _JS_MW_LIB_H
#define _JS_MW_LIB_H

/* punktT - podstawowy typ dla wsp�rz�dnych na p�aszczy�nie */

typedef struct {
  int x, y;
} punktT;

/* labiryntT - struktura danych do zapami�tywania labirynt�w */

typedef struct {
	int xsize, ysize;
	punktT startpos;
	char** powierzchnia;
} labiryntT;

/* kierunkiT - reprezentuje mo�liwe kierunki w labiryncie */

typedef enum { North, East, South, West} kierunkiT;

int CzytajLabirynt(char*); /* czytanie z pliku */
int GenerujLabirynt(int, int); /* generowanie labiryntu */
int PustyLabirynt(char, int, int, char); /* stworzenie pustego labiryntu (wype�nionego znakami znak) */
punktT PobierzStart(void); /* wsp�rz�dne punktu startowego */
punktT PunktObok(punktT, kierunkiT); /* wsp�rz�dne punktu w danym kierunku */
int NaZewnatrz(punktT, char); /* czy punkt jest poza labiryntem? */
int JestMur(punktT, char); /* czy w danym punkcie jest �ciana? */
void Zaznacz(punktT, char); /* zaznaczenie punktu */
void Odznacz(punktT); /* odznaczenie punktu */
int JestZaznaczone(punktT, char); /* czy punkt jest zaznaczony? */
int RozmiarX(char); /* podaje rozmiar x */
int RozmiarY(char); /* podaje rozmiar y */

void KlientaLabRysuj(int xoff, int yoff); /* rysuje labirynt klienta */
                   
#endif

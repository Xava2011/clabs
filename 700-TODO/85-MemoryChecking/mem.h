
#ifndef MEM_INCLUDED
#define MEM_INCLUDED
#include "except.h"

/* Przekazanie `nbytes<=0' jakiejkolwiek funkcji 
   jest SBW (Sprawdzanym B��dem Wykonania Programu) */

extern const Except_T Mem_Failed;

/* Przydziel `nbytes' bajt�w pami�ci i zwr�� wska�nik do 
   pierwszego bajtu. Pami�� nie jest inicjalizowana. 
   Je�li `Mem_alloc' zg�osi wyj�tek, to `file' i `line'
   informuj� o~miejscu b��du. */
extern void *Mem_alloc (long nbytes,
	const char *file, int line);

/* Przydziel pami�� na tablic� o `count' elementach, z kt�rych ka�dy
   zajmuje `nbytes' bajt�w, i zwr�� wska�nik do pierwszego bajtu. Jest
   SBW je�li `count<=0'. Przydzielona pami�� jest zerowana, co
   niekoniecznie musi oznacza� inicjalizacji wska�nikami zerowymi
   lub liczbami rzeczywistymi 0.0. Je�li `Mem_calloc' zg�osi wyj�tek, to
   `file' i `line' informuj� o~miejscu b��du. */
 extern void *Mem_calloc(long count, long nbytes,
	const char *file, int line);

/* Je�li `ptr<>NULL', to zwolnij pami��. Jest NBW je�li 
   blok pami�ci zaczynaj�cy si� w `ptr' nie zosta� przydzielony 
   przez uprzednie wywo�anie `Mem_alloc' lub `Mem_calloc'.
   Implementacja mo�e skorzysta� z `file' i `line' informuj�c 
   o b��dach w wykorzystaniu pami�ci. */
extern void Mem_free(void *ptr,
	const char *file, int line);

/* Zmie� rozmiar bloku pami�ci zaczynaj�cej si� od `ptr'
   i zwr�� wska�nik do pierwszego bajtu nowego bloku.
   Je�li `nbytes' jest wi�ksze od rozmiaru poprzedniego
   bloku pami�ci, to dodatkowe bajty s� niezainicjalizowane.
   Je�li `Mem_resize' zg�osi wyj�tek `Mem_failed', to `file'
   i `line' informuj� o miejscu b��du. Jest SBW je�li `ptr==Null'
   i NBW je�li blok pami�ci zaczynaj�cy si� w `ptr' nie zosta�
   przydzielony przez uprzednie wywo�anie `Mem_alloc' 
   lub `Mem_calloc'. */
extern void *Mem_resize(void *ptr, long nbytes,
	const char *file, int line);

/* Przydziel `nbytes' i zwr�� wska�nik do pierwszego bajtu. 
   Przydzielone bajty nie s� inicjalizowane. */
#define ALLOC(nbytes) \
	Mem_alloc((nbytes), __FILE__, __LINE__)

/* Przydziel pami�� na tablic� rozmiaru `count', kt�rej ka�dy 
   element zajmuje `nbytes' bajt�w. Jest SBW je�li `count<=0'. 
   Przydzielona pami�� jest wyzerowana. */
#define CALLOC(count, nbytes) \
	Mem_calloc((count), (nbytes), __FILE__, __LINE__)

/* Zwr�� blok pami�ci dostatecznie du�y aby pomie�ci� `*p',
   wstaw do `p' adrese pocz�tku bloku i zwr�� ten adres.
   NEW0 zeruje przydzielon� pami��, a NEW tego nie robi. 
   Oba makra wyliczaj� `p' dok�adnie raz. */
#define  NEW(p) ((p) = ALLOC((long)sizeof *(p)))
#define NEW0(p) ((p) = CALLOC(1, (long)sizeof *(p)))

/* Je�li `ptr<>NULL', to zwolnij pami�� i~wyzeruj `ptr'. 
   Wska�nik `ptr' jest wyliczany wi�cej ni� raz. */ 
#define FREE(ptr) ((void)(Mem_free((ptr), \
	__FILE__, __LINE__), (ptr) = 0))

/* Zmie� rozmiar bloku pami�ci zaczynaj�cej od `ptr' do `nbytes'
   i zmie� `ptr' tak aby wskazywa�a na jej pocz�tek. Wska�nik
   `p' jest wyliczany wiecej ni� raz. */
#define RESIZE(ptr, nbytes) 	((ptr) = Mem_resize((ptr), \
	(nbytes), __FILE__, __LINE__))

#endif

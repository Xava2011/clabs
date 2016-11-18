
#ifndef LIST_INCLUDED
#define LIST_INCLUDED
#define T List_T

typedef struct T *T;
struct T {
	T rest;
	void *first;
};

/* UWAGA: Wska�nik null T dla argumentu `list' 
          jest interpretowany jako lista pusta. */

/* Dopisz `tail' do `list' i zwr�� `list'. Je�li list=null, zwr�� `tail'. */
extern T      List_append (T list, T tail);

/* Utw�rz i zwr�� kopi� `list'. */
extern T      List_copy   (T list);

/* Utw�rz i zwr�� list�, o elementach ``...'' a� do
   napotkania pierwszego wska�nika null. */
extern T      List_list   (void *x, ...);

/* Przypisz `list->first' do `*x'. Je�li `x' nie jest r�wne null
   zwolnij pami�� zaj�t� przez `list' i zwr�� `list->rest'.
   W przypadku list==nul, zwr�� null i nie zmieniaj `*x'. */
extern T      List_pop    (T list, void **x);

/* Dopisz nowy w�ze� zawieraj�cy `x' do pocz�tku `list' 
   i zwr�� nowo utworzon� list�. */
extern T      List_push   (T list, void *x);

/* Odwr�� w miejscu kolejno�� element�w na `list' i zwr��
   nowo utworzon� list�. */
extern T      List_reverse(T list);

/* Zwr�� liczb� element�w `list'. */
extern int    List_length (T list);

/* Zwolnij pami�� i wyzeruj `*list'. 
   Jest SBW (Sprawdzanym B��dem Wykonania Programu, 
   ang. CRE -- Checked Runtime Error) je�li list==null. */
extern void   List_free   (T *list);

/* Wywo�aj `apply(&p->first,cl)' dla ka�dego w�z�a p `list'.
   Jest NBW (Niesprawdzanym B��dem Wykonania Programu,
   ang. URE -- Unchecked Runtime Error), je�li `apply'
   zmienia w�z�y `list'. */
extern void   List_map    (T list,
	void apply(void **x, void *cl), void *cl);

/* Utw�rz tablic� o N+1 elementach z pierwszych N element�w
   `list' i zwr�� wska�nik na pierwszy element tablicy.
    Wstaw jako N-ty element `end' do tablicy. */
extern void **List_toArray(T list, void *end);

#undef T
#endif

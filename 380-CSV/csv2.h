
/* csv2.h: drugi interfejs dla CSV */

#ifndef CSV2_H_INCLUDED
#define CSV2_H_INCLUDED

/*  Funkcja czyta jeden wiersz z otwartego pliku wej�ciowego f.
    Zwraca wska�nik do wczytanego wiersza z usuni�tym znakiem `\n' 
    lub zwraca NULL po napotkaniu EOF.
    Wiersz mo�e by� dowolnej d�ugo�ci.  */

extern const char *csv_getline(FILE *f);  /* pobierz kolejny wiersz */

/*  Funkcja zwraca n-te pole wiersza wczytanego przez ostatnie
    wywo�anie csv_getline lub NULL je�li n<0 albo n jest wi�ksze
    od indeksu ostatniego pola.
    Indeksem pierwszego pola jest 0.
    Cudzys�owy otaczaj�ce pole s� usuwane.
    W obr�bie "..." podw�jny znak cudzys�owu "" jest zast�powany
    przez jeden znak " oraz przecinek nie jest separatorem.
    W polach nie otoczonych cudzys�owami, cudzys��w jest zwyk�ym
    znakiem.
    P�l mo�e by� dowolnie wiele i mog� by� dowolnej d�ugo�ci.
    Zachowanie funkcji jest nieokre�lone przed pierwszym
    wywo�aniem funkcji csv_getline.  */

extern const char *csv_field(int n);  /* przeka� pole o numerze n */

/*  Funkcja zwraca liczb� p�l w wierszu ostatnio wczytanym 
    przez csv_getline.
    Zachowanie funkcji jest nieokre�lone przed pierwszym
    wywo�aniem funkcji csv_getline.  */

extern int csv_nfield(void);  /* przeka� liczb� p�l */

#endif

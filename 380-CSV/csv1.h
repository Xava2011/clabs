
/* csv1.h: pierwszy interfejs dla CSV */

/* Funkcja czyta wiersz z otwartego pliku wej�ciowego f
    i dzieli go na pola. Funkcja zwraca liczb� znalezionych p�l. */

extern int csv_getline(FILE *f);

/* Tablica wska�nik�w do p�l. */

extern char *csv_field[];

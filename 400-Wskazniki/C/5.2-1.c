
#include <stdio.h>
#include <ctype.h>

/* getint: wczytaj nast�pn� liczb� ca�kowit� 
   Funkcja zwraca: 
     EOF -- gdy napotka koniec pliku
       0 -- je�li kolejne znaki z wej�cia nie tworz� liczby
      >0 -- je�li na wej�ciu podano podano poprawn� liczb�
*/
int getint(int *pn) {
  int c, sign;
  while (isspace(c=getc(stdin))) /* pomi� bia�e znaki */
    ;
  if (!isdigit(c) && c!=EOF && c!='+' && c!='-') {
    ungetc(c,stdin); /* to nie jest liczba */
    return 0;
  }
  sign = (c=='-') ? -1 : 1;
  if (c=='+' || c=='-')
    c = getc(stdin);
  for (*pn=0; isdigit(c); c=getc(stdin))
    *pn = 10 * *pn + (c-'0');
  *pn *= sign;
  if (c!=EOF)
    ungetc(c,stdin);
  return c;
}

int main() {
  int *liczba_p, wynik;
  wynik=getint(liczba_p);
  printf("Wczytano liczb�: %d\n", *liczba_p);
  printf("Warto�� wyliczona przez `getint' to: %d\n", wynik);
  return 0;
}

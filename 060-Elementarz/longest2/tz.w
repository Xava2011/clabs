% --------------------------------------------------------------------
% This file is part of CWEB-NLS.
% It is distributed WITHOUT ANY WARRANTY, express or implied.
%
% Copyright (C) 2002 W{\l}odek Bzyl
% --------------------------------------------------------------------
\getCVSrevision$Revision: 1.2 $
\getCVSdate$Date: 2004/03/10 10:34:57 $
\getCVSsource$Source: /var/cvs/wyklady/JP1-L/14-Elementarz/longest1/tz.w,v $
% --------------------------------------------------------------------

% Strona tytu�owa --

\def\title{Tablice znakowe}
\def\topofcontents{\null\vfill
  \centerline{\titlefont tz.w --- przyk�ad programu opisowego}
  \vskip 15pt
  \centerline{(wersja \CVSrevision)}
  \vskip1in
  \vfill}
\def\botofcontents{\parskip=0pt \parindent=0pt
  \vskip 0pt plus 1filll
  Copyright \copyright\ 2003 W�odek Bzyl
  \bigskip
  Dokument ten zawiera przyk�ad z rozdzia�u 1.9 ksi��ki K\&R.
  \bigskip
  \line{\tt\CVSsource\hfil\CVSdate}\par}

% -- albo data --

%\datethis

% Polskie litery w nazwach zmiennych
\noatl
@l b1 xa
@l e6 xc
@l ea xe
@l b3 xl
@l f1 xn
@l f3 xo
@l b6 xs
@l bc xx
@l bf xz
@l a1 xA
@l c6 xC
@l ca xE
@l a3 xL
@l d1 xN
@l d3 xO
@l a6 xS
@l ac xX
@l af xZ
@f line x

\secpagedepth=2 % sekcje `@@*1' nie b�d� zaczyna� si� od nowej strony

@ Najlepszym sposobem na nauczenie si� j�zyka \CEE/, jest samodzielne
pisanie program�w w~tym j�zyku. Oto wersja opisowa programu
z~rozdzia�u 1.9 ksi��ki K\&R.

Najcz�ciej u�ywanymi tablicami w~j�zyku \CEE/ s� tablice znak�w.
Aby pokaza� spos�b korzystania z~tych tablic oraz funkcje
manipuluj�ce nimi, napiszmy program, kt�ry czyta zbi�r wierszy
i~wypisuje najd�u�szy.

@c
@<W��czane pliki nag��wkowe@>@;
@<Deklaracje u�ytych funkcji@>@;
int main() {
  @<Zmienne pomocnicze funkcji |main|@>@#
  @<Znajd� najd�u�szy wiersz@>@/
  @<Wypisz najd�u�szy wiersz@>@#
  return EXIT_SUCCESS;
}
@<Definicje u�ytych funkcji@>@;

@ Ze powy�szego schematu jasno wynika, �e program w~naturalny
spos�b dzieli si� na cz�ci. W~jednej z~nich jest czytany nowy
wiersz, w~innej sprawdza si� jego d�ugo��, w~jeszcze innej
zachowuje wiersz, reszta za� steruje ca�ym procesem.

@<Znajd� najd�u�szy wiersz@>=
  while (@<istnieje inny wiersz@>) {
    if (@<jest d�u�szy od poprzednio najd�u�szego@>) {
      @<zachowaj go@>@;
      @<zachowaj jego d�ugo��@>@;
    }
  }

@ Problem da� si� �adnie podzieli� na zadania, dobrze by�oby wi�c
napisa� program w~ten sam spos�b. Napiszmy zatem najpierw
oddzieln� funkcj� |getline|, pobieraj�c� z~wej�cia nast�pny
wiersz. {\it Spr�bujemy napisa� j� tak, aby mog�a by� u�ywana
w~innych programach}. Jako minimum funkcja |getline| musi zwraca�
sygna� o~napotkaniu ko�ca pliku. Mo�na zaakceptowa� zero jako
sygna� ko�ca pliku, nie jest on bowiem nigdy poprawn� d�ugo�ci�
wiersza. Ka�dy wiersz zawiera co najmniej jeden znak; nawet wiersz
sk�adaj�cy si� tylko ze znaku nowego wiersza ma d�ugo�� 1.

Powodem, dla kt�rego w~deklaracji tablicy podaje si� jej rozmiar,
jest rezerwacja pami�ci. W~funkcji |getline| d�ugo�� tablicy |s|
nie jest potrzebna, poniewa� rozmiar tablicy jest okre�lony
w~|main|. Instrukcja |return| s�u�y funkcji |getline| do odes�ania
warto�ci w~miejsce wywo�ania.

@<Deklaracje u�ytych funkcji@>=
int getline(char s[], int lim);

@ Po stwierdzeniu, �e dany wiersz jest d�u�szy od poprzednio
najd�u�szego, nale�y go gdzie� zapami�ta�. Sugeruje to stworzenie
funkcji |copy| przepisuj�cej nowy wiersz w~bezpieczne miejsce.

@<Deklaracje u�ytych funkcji@>=
void copy(char to[], char from[]);

@ @<Zmienne pomocnicze funkcji |main|@>=
int  len; /* d�ugo�� bie��cego wiersza */
int max = 0; /* poprzednia maksymalna d�ugo�� */
char line[MAXLINE]; /* bie��cy wiersz z wej�cia */
char longest[MAXLINE]; /* przechowywany maksymalny wiersz */

@ Je�li |max=0|, to nic nie przeczytali�my.

@<Wypisz najd�u�szy wiersz@>=
if (max>0) {
  printf("%s",longest);
}

@ @<istnieje inny wiersz@>=
(len=getline(line,MAXLINE))>0

@ @<jest d�u�szy od poprzednio najd�u�szego@>=
len>max

@ @<zachowaj go@>=
copy(longest,line);

@ @<zachowaj jego d�ugo��@>=
max=len;

@ Funkcja |getline| wstawia znak |'\0'| (znak |null|: nic, kt�rego
warto�ci� jest zero) na koniec tworzonej przez siebie tablicy, aby
zaznaczy� koniec ci�gu znak�w.

@<Definicje u�ytych funkcji@>=
int getline(char s[], int lim) {
  int c, i;
  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
    s[i]=c;
  }
  if (c=='\n') {
    s[i]=c;
    ++i;
  }
  s[i]='\0';
  return i;
}

@ @<Definicje u�ytych funkcji@>=
void copy(char to[], char from[]) {
  int i;
  i=0;
  while ((to[i]=from[i])!='\0')
    ++i;
}

@ @<W��czane pliki nag��wkowe@>=
#include <stdio.h> /* definicja |printf| */
#include <stdlib.h> /* definicja |EXIT_SUCCESS| */
#define MAXLINE 1024 /* maksymalny rozmiar wiersza */

@* Skorowidz. 
Poni�ej znajdziesz list� identyfikator�w u�ytych w~programie 
\.{tz.w}. Liczba wskazuje na numer sekcji, w~kt�rej u�yto identyfikatora,
a~liczba podkre�lona --- numer sekcji w~kt�rej zdefiniowano identyfikator.

#!/bin/ch
/* 
   Poniewa� plik ten ma ustawione prawa wykonania
   i pierwszy wiersz rozpoczynaj� dwa znaki
   `#!' (w pow�oce znak `#' rozpoczyna komentarz),
   to pow�oka przeka�e wykonanie tego pliku programowi
   wymienionemu po tych znakach, czyli `/bin/ch'.

   Zatem plik `hello.c' mo�na uruchomi� z wiersza polece�.

   W terminologii j�zyka Ch pliki napisane w C 
   nazywamy `poleceniami'. Dlatego 
   plik ten jest poleceniem j�zyka Ch.
*/

#include <stdio.h>

int main() {
  printf("Witaj �wiecie!\n");
}

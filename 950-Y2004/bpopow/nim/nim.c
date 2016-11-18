/*  
 *  File: nim.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:40:34 $
 *
    Implementacja interfejsu do gry w NIM.
 */

#include "nim.h"

/*  Funkcja zwraca TRUE je�li ze stosu, kt�ry zawiera 
    nCoins �eton�w mo�na pobra� nTaken �eton�w. */

static int MoveIsLegal(rowsT ile, int tab[]);

/*  Dla podanej liczby �eton�w `nCoins' funkcja ta 
    szuka dobrego ruchu. Je�li w tej dla stosu
    �eton�w sk�adaj�cego si� z nCoins mo�na wykona�
    wygrywaj�cy ruch, to funkcja zwraca TRUE.
    W przeciwnym wypadku funkcja zwraca sta��
    `NoGoodMove'.
    Jest to funkcja rekurencyjna. Rekurencja jest 
    tu wykorzystana do znalezienia dobrego ruchu,
    czyli ruchu stawiaj�cego przeciwnika w z�ej
    pozycji, gdzie z�a pozycja to taka pozycja
    w kt�rej nie mo�na wykona� dobrego ruchu.
 */

static rowsT FindGoodMove(int tab[]);

/*  Funkcja zwraca TRUE je�li liczba `nCoins' jest 
    z�� pozycj�, gdzie z�� pozycj� jest taka pozycja
    w kt�rej nie mo�na wykona� dobrego ruchu.
    Je�li pozosta� 1 �eton, to taka pozycja oczywi�cie
    jest z�a. Reprezentuja ona przypadek prostym rekursji.
 */

static int IsBadPosition(int tab[]);

/* 
 *  Eksportowane funkcje 
 */

void AnnounceWinner(int nCoins , playerT whoseTurn)
{
  if (nCoins==0) {
    printf("Zabra�e� ostatni �eton i przegra�e�!\n");
  } else {
    printf("Pozosta� jeden �eton.\n");
    switch (whoseTurn) {
    case Human: printf("Wygra�em ;)\n"); break;
    case Computer: printf("Przegra�em ;(\n"); break;
    }
  }
}

rowsT GetUserMove(int tab[]) {
  rowsT ile;

  while (1 == 1) {
    printf("Z kt�rego stosiku? ");
    scanf("%d",&(ile.row));

    printf("Ile �eton�w zabierasz? ");
    /*    nTaken=GetInteger();*/
    scanf("%d",&(ile.number));

    if (MoveIsLegal(ile, tab))
      break;
    printf("Oszukujesz!\n");
    printf("Mo�esz zabra� od 1 do 3 �eton�w.\n");
    printf("Liczba �eton�w na stosach: %d, %d, %d.\n",tab[1], tab[2], tab[3]);
  }
  return ile;
}

rowsT ChooseComputerMove(int tab[])
{
  rowsT ile;

  ile = FindGoodMove(tab);
  if (ile.number == NoGoodMove)
    ile.number = 1;
  return ile;
}

/* 
 *  Prywatne funkcje tego interfejsu.
 */

static int MoveIsLegal(rowsT ile, int tab[]) {
  int warunek1, warunek2, warunek3;

  warunek1 = (ile.row>0 && ile.row<=NofRows);
  warunek2 = (ile.number>0 && ile.number<=MaxTake);
  warunek3 = (ile.number<=tab[ile.row]);

  /*  printf("%d\n", watunek3);*/

  return (warunek1 && warunek2 && warunek3);
}

static rowsT FindGoodMove(int tab[])
{
  int i,j;
  rowsT ile;
  int temp;

  for (i = 1; i<=NofRows; i++){
    for (j = 1; j<=MaxTake; j++){
      ile.row = i;
      ile.number = j;
      temp = tab[ile.row]; /*!!!!!!!!!!*/

      if (MoveIsLegal(ile, tab)){
	/*	printf("Legalny dla %d i %d\n",tab[ile.row],ile.number);*/
	tab[ile.row] -= ile.number;
	if(IsBadPosition(tab)){
	/*  && IsBadPosition(tab)){*/
	tab[ile.row] = temp;
	return ile;	
	}
      tab[ile.row] = temp;
      }
      /*      else printf("Nielegalny dla %d i %d\n",tab[ile.row],ile.number);*/
      tab[ile.row] = temp;
    }
  }
  ile.row = 1;
  ile.number = NoGoodMove;
  /*  while(MoveIsLegal(ile, tab)==1)
      (ile.row)++;*/
  return ile;
}

static int IsBadPosition(int tab[]){
  int warunek1, warunek2;
  rowsT wzor,wynik;
  wzor.row = 1;
  wzor.number = NoGoodMove;

  /*  Wypis(tab);*/

  if (tab[1] + tab[2] + tab[3] == 1) 
    return 1;
  /*  return (FindGoodMove(tab) == wzor);*/
  wynik = FindGoodMove(tab);
  warunek1 = (wynik.row == wzor.row);
  warunek2 = (wynik.number == wzor.number);
  return (warunek1 && warunek2);
}

void Wypis(int tab[]){
  int i;

  for(i = 1; i<=3; i++)
    printf("%d: %d   ",i,tab[i]);
  printf("\n");
}

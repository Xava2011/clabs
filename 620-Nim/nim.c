/*  
 *  File: nim.c
 *
 *  $Revision: 1.3 $
 *  $Date: 2004/01/12 09:40:01 $
 *
    Implementacja interfejsu do gry w NIM.
 */

#include "nim.h"

/*  Funkcja zwraca TRUE je�li ze stosu, kt�ry zawiera 
    nCoins �eton�w mo�na pobra� nTaken �eton�w. */

static bool MoveIsLegal(int nTaken, int nCoins);

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

static int FindGoodMove(int nCoins);

/*  Funkcja zwraca TRUE je�li liczba `nCoins' jest 
    z�� pozycj�, gdzie z�� pozycj� jest taka pozycja
    w kt�rej nie mo�na wykona� dobrego ruchu.
    Je�li pozosta� 1 �eton, to taka pozycja oczywi�cie
    jest z�a. Reprezentuja ona przypadek prostym rekursji.
 */

static bool IsBadPosition(int nCoins);

/* 
 *  Eksportowane funkcje 
 */

void AnnounceWinner(int nCoins, playerT whoseTurn)
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

int GetUserMove(int nCoins)
{
  int nTaken, limit;
  while (TRUE) {
    printf("Ile �eton�w zabierasz? ");
    nTaken=GetInteger();
    if (MoveIsLegal(nTaken,nCoins))
      break;
    limit=(nCoins<MaxTake) ? nCoins : MaxTake;
    printf("Oszukujesz!\n");
    printf("Mo�esz zabra� od 1 do %d �eton�w.\n",limit);
    printf("Liczba �eton�w na stosie: %d.\n",nCoins);
  }
  return nTaken;
}

int ChooseComputerMove(int nCoins)
{
  int nTaken;
  nTaken=FindGoodMove(nCoins);
  if (nTaken==NoGoodMove)
    nTaken=1;
  return nTaken;
}

/* 
 *  Prywatne funkcje tego interfejsu.
 */

static bool MoveIsLegal(int nTaken, int nCoins)
{
  return nTaken>0 && nTaken<=MaxTake && nTaken<=nCoins;
}

static int FindGoodMove(int nCoins)
{
  int nTaken;
  for (nTaken=1; nTaken<=MaxTake; nTaken++)
    if (MoveIsLegal(nTaken,nCoins) &&
	IsBadPosition(nCoins-nTaken))
      return nTaken;
  return NoGoodMove;
}

static bool IsBadPosition(int nCoins)
{
  if (nCoins==1) 
    return TRUE;
  return (FindGoodMove(nCoins)==NoGoodMove);
}

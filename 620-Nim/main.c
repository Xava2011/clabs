/*  
 *  File: main.c
 *
 *  $Revision: 1.2 $
 *  $Date: 2004/01/12 09:40:01 $
 *
    Program ten symuluje gr� w NIM, w kt�rej
    stos sk�ada si� z 13 �eton�w.
    Dwaj gracze wykonuj� na przemian ruchy usuwaj�c
    ze stosu 1, 2 lub 3 �etony. Gracz, kt�ry
    zabiera ostatni �eton przegrywa. Drugim
    graczem jest komputer.
 */

#include <stdio.h>
#include <stdlib.h>
#include "nim.h"

#define InitialCoins 64
void GiveInstructions(void);

int main() 
{
  int nCoins, nTaken;
  playerT whoseTurn;

  GiveInstructions();
  nCoins=InitialCoins;
  whoseTurn=Human;
  while (nCoins>1) {
    printf("Liczba �eton�w na stosie: %d.\n",nCoins);
    switch (whoseTurn) {
    case Human:
      nTaken=GetUserMove(nCoins);
      whoseTurn=Computer;
      break;
    case Computer:
      nTaken=ChooseComputerMove(nCoins);
      printf("Bior� %d.\n",nTaken);
      whoseTurn=Human;
      break;
    }
    nCoins-=nTaken;
  }
  AnnounceWinner(nCoins,whoseTurn);
  return EXIT_SUCCESS;
}

void GiveInstructions(void) 
{
  printf("Witam w grze w NIM!\n");
  printf("Zaczynamy gr� ze stosem %d �eton�w.\n",InitialCoins);
  printf("Ruchy wykonywane s� na przemian.\n");
  printf("W ka�dym ruchu mo�na zabra� ze stosu od 1 do %d �eton�w.\n",MaxTake);
  printf("Gracz, kt�ry zabierze ostatni �eton przegrywa.\n");
  printf("\n");
}

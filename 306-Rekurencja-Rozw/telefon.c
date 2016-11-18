/*  
    Na przyciskach mojego telefonu przy cyfrach wydrukowano
    nast�puj�ce litery:

       1 -       6 - MNO
       2 - ABC   7 - PRS
       3 - DEF   8 - TUV
       4 - GHI   9 - WXZ
       5 - JKL   0 - 

    Czasami, aby u�atwi� zapami�tanie numeru, operator
    podaje s�owo. Na przyk�ad

       767   (SOS)
       4357  (HELP)
 
    itp.

    Napisa� funkcj� `ListMnemonics' generuj�c� wszystkie
    mo�liwe kombinacje liter odpowiadaj�ce podanej
    liczbie, podanej jako napis z�o�ony z cyfr.
    Na przyk�ad, wywo�anie ListMnemonics("723")
    powinno wygenerowa� nast�puj�cych 27 tr�jek:

       PAD PBD PCD RAD RBD RCD SAD SBD SCD
       PAE PBE PCE RAE RBE RCE SAE SBE SCE
       PAF PBF PCF RAF RBF RCF SAF SBF SCF

    Jakie kombinacje liter s� przy cyfrach na telefonie
    kom�rkowym. Czy w tym wypadku Twoje rozwi�zanie 
    te� zadzia�a?
 */

#include <stdio.h>
#include <stdlib.h>
#include "strlib.h"

char telephone[] = "ABCDEFGHIJKLMNOPRSTUVWXZ";

static void ListMnemonics(char *s);

int main() {
  ListMnemonics("731"); 
  return EXIT_SUCCESS;
}

static void ListMnemonics(char *s) {
  printf("???\n");
}

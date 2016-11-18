/*  
 *  File: telefon.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:39:04 $
 *
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
#include <string.h>
#include "strlib.h"

static void ListMnemonics(const char *s);

int main() {
  ListMnemonics("692"); 
  return EXIT_SUCCESS;
}

/* Jakie litery s� przy danej cyfrze na telefonie */
const char* letters_near_digit(char digit)
{
      switch (digit) {
            case '1': return "1";
            case '2': return "ABC";
            case '3': return "DEF";
            case '4': return "GHI";
            case '5': return "JKL";
            case '6': return "MNO";
            case '7': return "PRS";
            case '8': return "TUV";
            case '9': return "WXZ";
            case '0': return "0";
            default:
                      printf("%c: Nie ma takiej cyfry na klawiaturze telefonu!\n", digit);
                      return NULL;
      }
}

static void generate_combinations(const char* number, string combination)
{
      const char* letters;
      int len_letters, i;

      if (*number == '\0') {
            printf("%s\n", combination);
            return;
      }
      /* Litery pod pierwsz� cyfr� numeru */
      letters = letters_near_digit(*number);
      len_letters = strlen(letters);
      for (i = 0; i < len_letters; ++i)
            generate_combinations(number + 1, Concat(combination, CharToString(letters[i])));

}

static void ListMnemonics(const char *s) {
      generate_combinations(s, "");
}

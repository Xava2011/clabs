/*  
 *  File: telefon.c
 *
 *  $Revision: 1.1.1.1 $
 *  $Date: 2004/01/24 10:40:48 $
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
#include "strlib.h"

char telephone[] = "ABCDEFGHIJKLMNOPRSTUVWXZ";

static void ListMnemonics(string ,string);
string lst(char c);

int main() {
  ListMnemonics("633",""); 
  return EXIT_SUCCESS;
}

static void ListMnemonics(string s,string s2) {
 int dl_s,dl_s2,i;
 char c; 
 string s3,list;
 dl_s = StringLength(s);
 dl_s2= StringLength(s2); 
 
 if(dl_s2>=dl_s)
 printf("%s ",s2);
 else{
 c = IthChar(s,dl_s2);
 list = lst(c);
 
 for(i=0;i<StringLength(list);i++){
 s3=Concat(s2,SubString(list,i,i));
 ListMnemonics(s,s3);
  }
 printf("\n");
 }
}

string lst(char c){
int i;
char w;
string wy="";
if( (c!='0') && (c!='1')){
 for(i=0;i<3;i++) {
 w = telephone[ (c-'2')*3+i];
 wy=Concat(wy,CharToString(w));
   }
 return wy;
 }
 else  return "0";
}
 

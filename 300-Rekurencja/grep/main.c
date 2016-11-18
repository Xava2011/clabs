/*
   $Date: 2004/10/08 12:28:40 $
   $Revision: 1.1 $
*/

#include <stdio.h>
#include <stdlib.h>
#include "grep.h"

/* funkcja `main' dla programu `grep': szukanie `regexp' w plikach */

int main(int argc,char *argv[]) {
  int i, nmatch = 0;
  FILE *f;

  if (argc<2)
    fprintf(stderr,"U�ycie: grep regexp [PLIK]\n");
  if (argc==2) {
    if (grep(argv[1],stdin,NULL))
      nmatch++;
  } else {
    for (i=2; i<argc; i++) {
      f=fopen(argv[i],"r");
      if (f==NULL) {
	fprintf(stderr,"grep: nie mo�na otworzy� `%s'\n",argv[i]);
	continue;
      }
      /* poni�ej zamiast sparawdza� `argc>3' wystarczy�oby sprawdzi�
         `argc>2' (tak naprawd� ca�e wyra�enie warunkowe mo�na
         zast�pi�: `argv[i]'; czy mo�esz poda� jakie� powody
         za `argv>3'? 
      */
      if (grep(argv[1], f, argc>3 ? argv[i] : NULL)>0)
	nmatch++;

      fclose(f);
    }
  }  
  return EXIT_SUCCESS;
}

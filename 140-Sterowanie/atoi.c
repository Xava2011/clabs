/*  $Revision: 1.1 $
    $Date: 2004/11/19 12:38:30 $ 
*/

/* Zob. man atoi, sscanf */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  /* isspace, isdigit; ale te� atoi */

/* atoint: 
     zamie� s na liczb� ca�kowit�
*/
int atoint(char s[]);

int main()
{
  char *alpha = "  -21593  ";
  /*  char *alpha = "  -21593  "; */
  int result;

  result=atoint(alpha);
  printf("Wynik konwersji napisu `%s' na liczb� ca�kowit� -> %d\n", alpha, result); 
  return EXIT_SUCCESS;
}

/*  pomi� bia�e znaki, je�li wyst�puj�
    we� znak liczby, jesli wyst�puje
    we� cz�� ca�kowit� i przekszta�� j�.  
*/

int atoint(char s[])
{
  int i, n, sign;

  for (i=0; isspace(s[i]); i++)
    ;

  sign = s[i]=='-' ? -1 : 1;
  if (s[i]=='+' || s[i]=='-')
    i++;

  for (n=0; isdigit(s[i]); i++)
    n = 10*n+(s[i]-'0');

  return sign*n;
}

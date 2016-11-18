/*  
    $Revision: 1.4 $
    $Date: 2004/12/02 14:21:32 $

    GCD -- najwi�kszy wsp�lny dzielnik.
    Euklides udowodni�, �e GCD liczb x, y mo�na obliczy�
    w nast�puj�cy spos�b:
      (1) Je�li y dzieli x, to najwi�kszym wsp�lnym dzielnikiem
          jest y.
      (2) W przeciwnym wypadku, najwi�kszym wsp�lnym dzielnikiem
          jest r�wny najwi�kszemu wsp�lnemu dzielnikowi
          y i reszcie dzielenia x przez y. 
 
    Korzystaj�c z twierdzenia Euklidesa, napisa� program
    obliczaj�cy rekurencyjnie najwi�kszy wsp�lny dzielnik 
    z liczb podanych na wej�ciu.
 */

#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

int GCD(int x, int y);

int main()
{
  int m, n;
  printf("\tn = ? ");
  m = GetInteger();
  printf("\tm = ? ");
  n = GetInteger();
  printf("\tGCD(%d, %d) = %d\n", m, n, GCD(m,n));

  return EXIT_SUCCESS;
}

int GCD(int x, int y)
{

  return 0;
}

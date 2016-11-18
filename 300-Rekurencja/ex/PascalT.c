/*  
    $Revision: 1.5 $
    $Date: 2004/12/02 16:03:56 $

    Napisa� funkcj� rekurencyjn� C(n,k) obliczaj�c�
                          / n \
    wsp�czynnik Newtona  \ k /  (czyli liczb� podzbior�w 
    k-elementowych zbioru n-elementowego).

    Skorzysta� z w�asno�ci Tr�jk�ta Pascala:

        / n+1 \   =  /  n  \  +  / n \ 
        \  k  /      \ k-1 /     \ k /

        / n \  =  / n \  =  1
        \ 0 /     \ n /
 */

#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

int C(int n, int k);

int main()
{
  int x, y;
  printf("\tx = ? ");
  x = GetInteger();
  printf("\ty = ? ");
  y = GetInteger();
  printf("\tC(%d, %d) = %d\n", x, y, C(x,y));

  return EXIT_SUCCESS;
}

int C(int n, int k)
{

  return 0;
}

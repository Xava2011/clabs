
#include <stdio.h>
#include <math.h>

/* równanie kwadratowe ma pierwiastki */

int main() {
  double a=1, b=-5, c=6, x1, x2;
  x1=(-b-sqrt(b*b-4*a*c))/(2*a);
  x2=(-b+sqrt(b*b-4*a*c))/(2*a);
  printf("x1 = %f\n",x1);
  printf("x2 = %f\n",x2);
  return 0;
}

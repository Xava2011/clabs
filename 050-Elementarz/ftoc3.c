/* wypisz zestawienie temperatur Fahrenheita-Celsjusza
   dla f = 0,20,...300; pętla for */

#include <stdio.h>

int main() {
  for (int fahr = 0; fahr <= 300; fahr = fahr + 20) {
    printf("%3d%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }
}

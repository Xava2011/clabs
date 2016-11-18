/* 
   Przyk�ad programu korzystaj�cego z biblioteki
   j�zyka Ch u�atwiaj�cej tworzenie wykres�w.

   Wykres asteroidy?
*/

#include <math.h>
#include <numeric.h>
#include <chplot.h>

#define NUMPOINTS 720

int main() {
    array double three[NUMPOINTS] = (array int [NUMPOINTS])3;
    array double t[NUMPOINTS], x[NUMPOINTS], y[NUMPOINTS];
    class CPlot plot;
    linspace(t, 0, 8*M_PI); // `czas'
    /*
       Dlaczego poni�ej nie mo�na napisa� 
       po prostu pow(cos(0.25*t,3)) ?
    */
    x=pow(cos(0.25*t),three);
    y=pow(sin(0.25*t),three);
    plot.polarPlot(PLOT_ANGLE_RAD); // k�t w radianach
    plot.data2D(x,y);
    //    plot.sizeRatio(1);  -- wykres w kwadratcie
    // rysuj b�d� nie rysuj siatki: PLOT_ON / PLOT_OFF
    // siatka w uk�adzie prostok�tnym b�d� biegunowym:
    //    PLOT_GRID_RECTANGULAR / PLOT_GRID_POLAR
    plot.grid(PLOT_ON, PLOT_GRID_POLAR); 
    plot.plotting();
}

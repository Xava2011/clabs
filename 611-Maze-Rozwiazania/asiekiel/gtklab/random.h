/* Artur Siekielski, 30 pa�dziernika 2003
 * Funkcje obs�uguj�ce generator liczb losowych -- deklaracje */

#ifndef INCLUDED__RANDOM_H
#define INCLUDED__RANDOM_H

#include <time.h>
#include <stdlib.h>
#include <unistd.h>

/* Zainicjalizuj generator liczb losowych */
void init_random_gen(void);

/* Wylosuj liczb� ca�kowit� z przedzia�u from..to-1 */
int random_integer(int from, int to);

#endif

/* Jakub S�awi�ski (Slaughter House Entertainment Group)
 * plik g��wny mw_maze (maze walker)
 * mw_main.c
 */

#include "mw_maze.h"
#include "grafika.h"
#include "myfunkc.h"
#include "stany.h"
#include <stdlib.h>

int
main(int argc, char** argv)
{
	Inicjuj();
	Intro(); 
	Menu();
	Zakoncz();
	system("clear"); /* by oczy�ci� ekran */
	return 0;
}

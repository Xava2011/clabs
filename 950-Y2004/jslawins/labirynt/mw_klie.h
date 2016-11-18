/* Jakub S�awi�ski (Slaughter House Entertainment Group)
 * plik nag��wkowy do klienta gry maze walker
 * mw_klie.h
 */

#include "mw_lib.h"
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>

#ifndef _JS_MW_KLIE_H
#define _JS_MW_KLIE_H

typedef struct {
	char type; /* typ po��czenia z serwerem */
	int fds; /* deskryptor do komunikacji z serwerem */
	int fd; /* deskryptor gracza, do kt�rego si� pisze (serwer) */
	int fd2; /* deskryptor gracza, z kt�rego si� nas�uchuje (klient) */
	punktT pozycja; /* pozycja gracza */
	int id; /* identyfikator gracza */
	char name[10]; /* ksywa gracza */
	int ruchy; /* ilo�� wykonanych do tej pory ruch�w*/
	int miejsca; /* ilo�� miejsc na graczy */
	char* czygracz; /* czy dany gracz jest w grze */
	punktT* pozgraczy; /* pozycje wszystkich graczy */
	char** imionagraczy; /* imiona wszystkich graczy */
	struct timeval tv; /* znacznik czasowy klienta */
} klientT;

int KlientInicjuj(char, char*, char*); /* zainicjowanie dzia�ania klienta */
int PiszDoSerwera(char, char, char, char, char*); /* pisanie wiadomo�ci do serwera */
int Dzialaj(void); /* g��wna funkcja klienta (grafika - klawiatura - w grze) */
int DajFd(void); /* daje deskryptor klienta */
int DajRuchy(void); /* daje ruchy gracza */
int RozpPoj(void); /* rozpoczyna gr� jednoosobow� */
int RozpMulti(char); /* rozpoczyna gr� wieloosobow� */
char* WprTekst(char*, int); /* wprowadzanie okre�lonego tekstu */

#endif

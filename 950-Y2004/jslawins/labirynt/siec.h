/* Jakub S�awi�ski (Slaughter House Entertainment Group)
 * plik nag��wkowy do obs�ugi sieci
 * siec.h
 */

#ifndef _JS_SIEC_H
#define _JS_SIEC_H

int tcpSluchaj(int*, const char*, const char*, socklen_t*); /* tworzy nas�uchuj�ce gniazdo tcp */
int tcpPolacz(int*, const char*, const char*); /* ��czy si� przez tcp */

#endif

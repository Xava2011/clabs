/* Jakub S�awi�ski (Slaughter House Entertainment Group)
 * plik implementuj�cy obs�ug� sieci
 * siec.c
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int
tcpSluchaj(int* listenfd, const char *host, const char *serv, socklen_t *addrlenp)
{
	const int		on = 1;
	struct addrinfo	hints, *res, *ressave;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if (getaddrinfo(host, serv, &hints, &res) != 0) {
		return 1;
	}
	ressave = res;

	do {
		(*listenfd) = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if ((*listenfd) < 0)
			continue;		/* b��d -> pr�bujemy nast�pne */

		setsockopt((*listenfd), SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
		if (bind((*listenfd), res->ai_addr, res->ai_addrlen) == 0)
			break;			/* uda�o si� */

		close(*listenfd);	/* nie uda�o si� zbindowa� -> zamykamy i pr�bujemy nast�pne */
	} while ( (res = res->ai_next) != NULL);

	if (res == NULL) {	/* w og�le nie uda�o si� nic znale�� */
		return 1;
	}

	listen((*listenfd), 10);

	if (addrlenp)
		*addrlenp = res->ai_addrlen;	/* zwracamy wielko�� struktury adresu dla danego protoko�u */

	freeaddrinfo(ressave);

	return 0;
}

int
tcpPolacz(int* sockfd, const char *host, const char *serv)
{
	struct addrinfo	hints, *res, *ressave;

	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if (getaddrinfo(host, serv, &hints, &res) != 0) {
		return 1;
	}
	ressave = res;

	do {
		(*sockfd) = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if ((*sockfd) < 0)
			continue;	/* b��d -> pr�bujemy nast�pne */

		if (connect((*sockfd), res->ai_addr, res->ai_addrlen) == 0)
			break;		/* uda�o si� */

		close((*sockfd));	/* nie uda�o si� -> zamykamy i pr�bujemy nast�pne */
	} while ( (res = res->ai_next) != NULL);

	if (res == NULL) {	/* nie uda�o si� w og�le po��czy� */
		return 1;
	}

	freeaddrinfo(ressave);

	return 0;
}




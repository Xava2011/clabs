
/*  Program z ksi��ki: Brian W. Kernighan i Rob Pike 
  ,,Lekcja Programowania'', WNT 2002  */

/* eprintf: wypisz komunikat o b��dzie i zako�cz */
extern	void	eprintf(char *, ...);

/* estrdup: powiek napis, informuj w razie b��du */
extern	char   *estrdup(char *);

/* emalloc: funkcja malloc oraz informowanie o b��dzie */
extern	void   *emalloc(size_t);

/* progname: przeka� zapami�tan� nazw� programu */
extern	char   *progname(void);

/* setprogname: zapami�taj nazw� programu */
extern	void	setprogname(char *);

#define	NELEMS(a)  (sizeof(a) / sizeof(a[0]))

   
/*  Program z ksi��ki: Brian W. Kernighan i Rob Pike 
  ,,Lekcja Programowania'', WNT 2002  */

/*  Generowanie losowego tekstu algorytmem �a�cucha Markowa  */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "eprintf.h"

enum {
  NPREF	= 2,	 /* liczba s��w w prefiksie */
  NHASH	= 4093,	 /* rozmiar tablicy haszuj�cej stan�w */
  MAXGEN	= 10000	 /* maksymalna liczba s��w do wygenerowania */
};

typedef struct State State;
typedef struct Suffix Suffix;

struct State {	               /* prefiks + lista sufiks�w */
  char	*pref[NPREF];  /* s�owa prefiksu */
  Suffix	*suf;          /* lista sufiks�w */
  State	*next;         /* nast�pny element w tablicy haszuj�cej */
};

struct Suffix {         /* lista sufiks�w */
  char	*word;  /* sufiks */
  Suffix	*next;  /* nast�pny element na li�cie sufiks�w */
};

State	*lookup(char *prefix[], int create);
void	build(char *prefix[], FILE*);
void	generate(int nwords);
void	add(char *prefix[], char *word);

State	*statetab[NHASH];  /* tablica haszuj�ca stan�w */

char NONWORD[] = "\n";  /* nie mo�e wyst�pi� jako s�owo */

/*  funkcja main programu markov  */

int main(void)
{
  int i, nwords = MAXGEN;
  char *prefix[NPREF];  /* bie��cy prefiks ze standardowego wej�cia */
  
  int c;
  long seed;
  
  setprogname("markov");
  seed = time(NULL);
  
  srand(seed);
  for (i = 0; i < NPREF; i++)	/* ustal pocz�tkowy prefiks */
    prefix[i] = NONWORD;
  build(prefix, stdin);
  add(prefix, NONWORD);
  generate(nwords);
  return 0;
}  

const int MULTIPLIER = 31;  /* u�yty w funkcji hash() */

/*  hash: oblicz hasz dla tablicy sk�adaj�cej si� z NPREF napis�w  */
unsigned int hash(char *s[NPREF])
{
  unsigned int h;
  unsigned char *p;
  int i;
  
  h = 0;
  for (i = 0; i < NPREF; i++)
    for (p = (unsigned char *) s[i]; *p != '\0'; p++)
      h = MULTIPLIER * h + *p;
  return h % NHASH;
}

/*  lookup: wyszukaj prefiks lub utw�rz go jesli trzeba;
            funkcja przekazuje znaleziony lub utworzony wska�nik;
            w przeciwnym razie przekazuje NULL;
            tworz�c prefiks nie wywo�uje si� funkcji strdup,
            wi�c nie wolno p�niej zmienia� napis�w  */
State* lookup(char *prefix[NPREF], int create)
{
  int i, h;
  State *sp;
  
  h = hash(prefix);
  for (sp = statetab[h]; sp != NULL; sp = sp->next) {
    for (i = 0; i < NPREF; i++)
      if (strcmp(prefix[i], sp->pref[i]) != 0)
	break;
    if (i == NPREF)  /* znale�li�my */
      return sp;
  }
  if (create) {
    sp = (State *) emalloc(sizeof(State));
    for (i = 0; i < NPREF; i++)
      sp->pref[i] = prefix[i];
    sp->suf = NULL;
    sp->next = statetab[h];
    statetab[h] = sp;
  }
  return sp;
}

/*  addsuffix: uzupe�nij stan o sufiks; sufiks nie mo�e p�niej ulec zmianie  */
void addsuffix(State *sp, char *suffix)
{
  Suffix *suf;
  
  suf = (Suffix *) emalloc(sizeof(Suffix));
  suf->word = suffix;
  suf->next = sp->suf;
  sp->suf = suf;
}

/*  add: dodaj s�owo do listy sufiks�w i uaktualnij prefiks  */
void add(char *prefix[NPREF], char *suffix)
{
  State *sp;

  sp = lookup(prefix, 1);  /* utw�rz, je�li nie istnieje */
  addsuffix(sp, suffix);
  /* przesu� w d� elementy tablicy prefix */
  memmove(prefix, prefix+1, (NPREF-1)*sizeof(prefix[0]));
  prefix[NPREF-1] = suffix;
}

/*  build: pobierz dane wej�ciowe, zbufuj tablic� prefiks�w  */
void build(char *prefix[NPREF], FILE *f)
{
  char buf[100], fmt[10];
  
  /* utw�rz napis formatuj�cy; %s mo�e spowodowa� przepe�nienie bufora buf */
  sprintf(fmt, "%%%ds", sizeof(buf)-1);
  while (fscanf(f, fmt, buf) != EOF)
    add(prefix, estrdup(buf));
}

/*  generate: wypisuj na standardowym wyj�ciu po jednym 
              s�owie w ka�dym wierszu  */
void generate(int nwords)
{
  State *sp;
  Suffix *suf;
  char *prefix[NPREF], *w;
  int i, nmatch;
  
  for (i = 0; i < NPREF; i++)  /* skasuj pocz�tkowy prefiks */
    prefix[i] = NONWORD;
  
  for (i = 0; i < nwords; i++) {
    sp = lookup(prefix, 0);
    if (sp == NULL)
      eprintf("internal error: lookup failed");
    nmatch = 0;
    for (suf = sp->suf; suf != NULL; suf = suf->next)
      if (rand() % ++nmatch == 0) /* prawdopodobie�stwo = 1/nmatch */
	w = suf->word;
    if (nmatch == 0)
      eprintf("internal error: no suffix %d %s", i, prefix[0]);
    if (strcmp(w, NONWORD) == 0)
      break;
    printf("%s\n", w);
    memmove(prefix, prefix+1, (NPREF-1)*sizeof(prefix[0]));
    prefix[NPREF-1] = w;
  }
}

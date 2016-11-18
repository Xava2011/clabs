%{
/* Hopcroft JE, Ullman Jd. 
   Wprowadzenie do teorii automat�w.. 
   przyk�ad 4.3, s. 99. 
   L -- napisy sk�adaj�ce si� z jednakowej liczby symboli a i b.
 */

#include <stdio.h>
%}
%%
input: /* pusty */
  | input line
  ;
line: '\n'
  | S '\n' { printf("\tOK!\n"); }
  ;
S: 'a' B | 'b' A ;
A: 'a' | 'a' S | 'b' A A ;
B: 'b' | 'b' S | 'a' B B ;
%%
int yylex()
{
  int c;
 
  while ((c=getchar())==' ' || c=='\t') ;
  yylval=c;
  if (c==EOF) return(0);
  else return(c);
}
int main()
{
//  yydebug=1;
  yyparse();
}
int yyerror(char *s)
{
  fprintf(stderr, "\t%s\n", s);
}

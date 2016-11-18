%{
/* Hopcroft JE, Ullman Jd. 
   Wprowadzenie do teorii automat�w.. 
   przyk�ad 10.5, s. 285. 
   L -- �a�cuchy zr�wnowa�onych nawias�w (gdzie '#' jest znacznikiem ko�ca).
 */

#include <stdio.h>
%}
%%
input: /* pusty */
  | input line
  ;
line: '\n'
  | S '\n' { printf("\tOK!\n"); }
  | error '\n' { yyerrok; }
  ;
S: S '#' ;
S: S A | A ;
A: 'a' S 'b' | 'a' 'b' ;
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

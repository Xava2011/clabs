%{
  /*  $URL: http://manta.univ.gda.pl/svn/wb/labs/c/551-Bison/ex1.y $
      $Revision: 89 $

      bison -v ex1.y

      ex1.output  zawiera opisy konflikt�w przesuni�cie/redukcja.
      `.' wskazuje jaki fragment produkcji ju� by� analizowany, 
      (Dragon Book, s. 210, tzw. sytuacja)

      zob. te�  bison --help
   */
%}  

%token LICZBA

%%

wyr  :  wyr '+' wyr
     |  wyr '*' wyr
     |  '(' wyr ')'
     |  LICZBA
     ;

%%

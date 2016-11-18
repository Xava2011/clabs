/* 
    $Revision: 64 $
    $Date: 2004/04/16 18:22:47 $ 
    $URL: http://manta.univ.gda.pl/svn/wb/labs/c/540-BST/BT.h $
*/

#ifndef BT_h
#define BT_h

/* w zadaniach w�z�y drzew BST zawieraj� liczby ca�kowite */ 

struct node {
  int data;
  struct node* left;
  struct node* right;
};


/*  FUNKCJE POMOCNICZE  */


/*  zwr�� wska�nik do nowego w�z�a zawieraj�cego podan� warto��
    w polu data i NULL w polach left i right  */
struct node* new_node(int data);

/*  do podanego drzewa i podanej warto�ci wstaw j� do BST; 
    zwr�� wska�nik do nowego drzewa;
    standardowy trik pozwalaj�cy unikn�� parametr�w przekazywanych
    przez adres  */
struct node* insert(struct node* node, int data);

/*  zwr�� liczb� w�z��w drzewa  */
int size(struct node* node);

/*  zwr�� true je�li BST zawiera w�ze� zawierajacy w polu data target */
int lookup(struct node *node, int target);


/*  wypisz wszystkie w�z�y drzewa w porz�dku ,,inorder''  */
void printTree(struct node* node);

/*  wypisz `�adnie' drzewo na terminalu  */
void prettyPrintTree(struct node* node);

/*  wygeneruj losowe drzewo o podanej liczbie wierzcho�k�w  */
struct node* buildRandomTree(int number_of_nodes, int seed);



/*  ZADANIA                                                          */
/*  -----------------------------------------------------------------*/ 


/*  Zadanie 1.
    Oblicz ,,maksymaln� g��boko��'' drzewa BT, tj. liczb� w�z��w 
    na najd�u�szej �cie�ce od korzenia a� do najdalszego li�cia.   
    maxDepth pustego drzewa r�wna si� 0.  */

int maxDepth(struct node* node);


/*  Zadanie 2. 
    Wyszukaj najmniejsz� liczb� ca�kowit� w drzewie BST.
    To zadanie ma rozwi�zanie nierekurencyjne.  */

int minValue(struct node* node);


/*  Zadanie 3.
    `�cie�ka od korzenia do li�cia' jest ci�giem w�z��w zaczynaj�cym
    si� od korzenia, przechodz�c� w d� przez wszystkie w�z�y
    do li�cia (tj. w�z�a bez dzieci). 
    Puste drzewo nie zawiera takich �cie�ek. 
    Poni�sze drzewo zawiera dok�adnie cztery �cie�ki od korzenia
    do li�cia:
                          5
                         / \
                        4   6
                       /   / \
                      9   8   4 
                     / \       \
                    7   2       1
 
    �cie�ka 1:  5 4 9 7
    �cie�ka 2:  5 4 9 2
    �cie�ka 3:  5 6 8
    �cie�ka 4:  5 6 4 1

    Suma liczb na pierwszej �cie�ce r�wna si� 25, na drugiej -- 20,
    na trzeciej -- 19, na czwartej -- 16.

    Dla danego drzewa binarnego BT `r' i danej liczby `n' napisa� funkcj�
    hasPathSum(r,n) zwracaj�c� TRUE je�li drzewo zawiera �cie�k�
    od korzenia do li�cia na kt�rej liczby sumuj� si� do `n'.  */

int hasPathSum(struct node* node, int sum);


/*  Zadanie 4.
    Dla danego drzewa BT wypisa� wszystkie jego �cie�ki od korzenia
    li�cia, po jednej w jednym wierszu.  */

void printPaths(struct node* node);


/*  Zadanie 5.
    W podanym drzewie BT w ka�dym w�le zamieni� rolami wska�niki 
    `left' i `right'. Tak aby drzewo

            4                                   4
           / \                                 / \
          2   5    zamieni�o si� w drzewo     5   2
         / \                                     / \
        1   3                                   3   1
*/

void mirror(struct node* node);


/*  Zadanie 6.
    Dla danych dw�ch drzew, zwr�� TRUE je�li drzewa s�
    takie same, tj. sk�adaj� si� z w�z��w z takimi
    samymi warto�ciami i rozmieszczonymi w taki sam spos�b.  */

int sameTree(struct node* a, struct node* b);


/*  Zadanie 7.
    Napisz funkcj� zwracaj�c� TRUE je�li podane drzewo binarne
    BT jest drzewem BST i FALSE w przeciwnym wypadku. Na przyk�ad

      3                 3                   5                  5 
     / \   => TRUE     / \   => FALSE      / \   => TRUE      / \   => FALSE
    1   5             4   5               3   7              3   7  
                                         /                  / \
                                        1                  1   6
*/

int isBST(struct node* node);

#endif

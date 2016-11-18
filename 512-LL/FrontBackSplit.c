/*   Plik: FrontBackSplit.c
   Wersja: 31 X 2002

 Zadanie 9:
   Podan� list� rozdzieli� na dwie podlisty -- lew� i praw�
   po�ow�. Je�li liczba w�z��w jest nieparzysta, to ekstra element
   powinien zosta� do��czony do lewej listy. Na przyk�ad lista
   {2,3,5,7,11} powinna zosta� podzielona na {2,3,5} i {7,11}. */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utils.h"

void FrontBackSplit(struct node* source, 
		   struct node** frontRef, struct node** backRef) {
  // tw�j kod
}

void BasicCaller() {
  struct node* myList=NULL;
  struct node* myFront=NULL;
  struct node* myBack=NULL;
  Push(&myList,11);
  Push(&myList,7);
  Push(&myList,5);
  Push(&myList,3);
  Push(&myList,2);
  ShowLinkedList(myList);
  FrontBackSplit(myList,&myFront,&myBack);
  ShowLinkedList(myFront);
  ShowLinkedList(myBack);
  printf("Oryginalna lista:\n");
  ShowLinkedList(myList);
}

int main() {
  BasicCaller();
  return EXIT_SUCCESS;
}

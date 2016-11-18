#ifndef utils_h
#define utils_h

struct node {
  int data;
  struct node* next;
};

/* Zwr�� liczb� w�z��w na li�cie. */
int Length(struct node* head);

/* Dodaj nowy w�ze�, do listy *headRef
   i umie�� w w�le w polu .data liczb� newData. */
void Push(struct node** headRef, int newData);

/* Zbuduj list� {1, 2, 3} i zwr�� wska�nik do niej. */
struct node* BuildOneTwoThree(void);

/* Wypisz wszystkie elementy listy head. */
void ShowLinkedList(struct node* head);

#endif

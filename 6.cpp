#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int number;
  Node *next;
};

Node *createNode(int number) {
  Node *insert = (Node*) malloc(sizeof(Node));
  insert->number = number;
  insert->next = NULL;
  return insert;
}

void pushHead(Node **head, Node **tail, int number) {
  Node *temp = createNode(number);
  if(!*head) {
    *head = *tail = temp;
  } else {
    temp->next = *head;
    *head = temp;
  }
}

void pushTail(Node **head, Node **tail, int number) {
    Node *temp = createNode(number);
  if(!*head) {
    *head = *tail = temp;
  } else {
    (**tail).next = temp;
    *tail = temp; 
  }
}

Node *recursiveLink (Node **head) {
  if(!*head) { // kalau isinya kosong
    return NULL;
  } 
  if(!(**head).next) { // kalau head->next udah di trakhir
      return *head; // return node trakhir
  } 
  Node *temp = recursiveLink(&(**head).next); // ini rekursif sampai node trakhir
  (**head).next->next = *head; // rekursif pointer ke node trakhir bersamaan ganti nextnya
  (**head).next = NULL;
  return temp;
}

void printLink(Node **head) {
  Node *temp = *head;
  while(temp) {
    printf("%d ",temp->number);
    temp = temp->next;
  }
}
int main() {
  Node *head = NULL, *tail = NULL;
  int n;
  scanf("%d",&n); // jumlah element
  for(int i = 0 ; i < n;i++) {
    int num;
    scanf("%d",&num); getchar(); // input element anggapan sudah sorted
    pushTail(&head,&tail,num);
  }
  Node *temp = recursiveLink(&head);
  // for(int i = 0 ; i < n;i++) {
  //   pushHead(&newHead,&newTail,temp->number);
  //   temp = temp->next;
  // }
  printLink(&temp);
  return 0;
}

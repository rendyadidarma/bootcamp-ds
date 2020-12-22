#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int number;
  Node *next;
}*head = NULL, *tail = NULL;

Node *insertNode(int angka){
  Node *create = (Node*) malloc(sizeof(Node));
  create->number = angka;
  create->next = NULL;
  return create;
}

void pushHead(int angka){
  Node *temp = insertNode(angka);
  if(!head){
    head = tail = temp;
  } else {
    temp->next = head;
    head = temp;
  }
}
void pushTail(int angka){
  Node *temp = insertNode(angka);
  if(!head){
    head = tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
}


void removeDup() {
  Node *temp = head;
  if(!temp)
    return;
  
  while(temp->next) {
    if(temp->number == temp->next->number) {
      Node *sambung = temp->next->next;
      temp->next = NULL; // supaya gak berbekas
      free(temp->next);
      temp->next = sambung;
    }
    else 
      temp = temp->next;
  }
}

void printNode() {
  Node *temp = head;
  while(temp) {
    printf("%d\n", temp->number);
    temp = temp->next;
  }
}

int main() {
  int n;
  printf("Berapa angka : ");
  scanf("%d",&n); getchar();
  for(int i = 0; i < n;i++){
    printf("Input angka %d : ",i+1);
    int num;
    scanf("%d",&num); getchar();
    pushTail(num); // 2 2 3 3 4 5
  }
  removeDup();
  printNode();

  return 0;
}
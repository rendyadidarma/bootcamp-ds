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

void pushTail(int angka){
  Node *temp = insertNode(angka);
  if(!head){
    head = tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
}

void getN(int N) {
  Node *temp = head;
  int count = 0;
  while(temp) {
    count++;
    temp = temp->next;
  }
   count = count - N;
  Node *temp1 = head;
  while(temp1 && count != 0) {
    temp1 = temp1->next;
    count--;
  }

  printf("%d\n", temp1->number);
}

int main() {
  int n;
  scanf("%d",&n); // berapa jumlah element
  getchar();
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d",&num); getchar();
    pushTail(num);
  }
  // 2 2 3 4 5 6 7 8 
  // misal mau cari 2 dari belakang jadi 7
  int search;
  scanf("%d",&search); // mau berapa dari belakang
  getchar();
  getN(search);
  
  return 0;
}
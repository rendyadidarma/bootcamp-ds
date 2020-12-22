#include <stdio.h>
#include <stdlib.h>

// 1. Given two sorted linked lists L1 and L2 of size M and N respectively
//    , merge them into one sorted linked list.

struct Node 
{
  int number;
  Node *next;
};

Node *insertNode(int number){
  Node *createNode = (Node*) malloc(sizeof(Node));
  createNode->number = number;
  createNode->next = NULL;
  return createNode;
}

void pushTail(Node **head, Node **tail, int angka){
  Node *temp = insertNode(angka);
  if(!*head){
    *head = *tail = temp;
  } else {
    (**tail).next = temp;
    *tail = temp;
  }
}

void printAll(Node **head){
  Node *temp = *head;
  while(temp){
    printf("%d ",temp->number);
    temp = temp->next;
  }
}


int main() {
  Node *head = NULL, *head2 = NULL, *tail = NULL, *tail2 = NULL;
  printf("Jumlah Data Pertama : "); // M = 3, N = 2
  int M; scanf("%d",&M); getchar();
  printf("Jumlah Data Kedua : ");
  int N; scanf("%d",&N); getchar();

  for(int i = 1; i <= M;i++){ //
    printf("Input Data Pertama [%d] : ",i);
    int n;
    scanf("%d", &n); getchar();
    pushTail(&head,&tail,n);
  }

  for(int i = 1; i <= N;i++){
    printf("Input Data Kedua [%d] : ",i);
    int num;
    scanf("%d", &num); getchar();
    pushTail(&head2,&tail2,num);
  }
  Node *headResult = NULL, *tailResult = NULL, *temp1 = head, *temp2 = head2;
  while(temp1 || temp2) { // selama salah satu masih ada true
    if(!temp1) { // kalau misalnya tempnya udah gak ada
      while(temp2) {
        pushTail(&headResult,&tailResult,temp2->number);
        temp2 = temp2->next;
      }
    } else if(!temp2) { // misal temp2 udah abis
      while(temp1) {
        pushTail(&headResult,&tailResult,temp1->number);
        temp1 = temp1->next;
      }
    } else { // selama dua duanya masih ada
      if(temp1->number > temp2->number) { 
        pushTail(&headResult,&tailResult,temp2->number);
        temp2 = temp2->next;
      } else {
        pushTail(&headResult,&tailResult,temp1->number);
        temp1 = temp1->next;
      }
    }
  }

  printAll(&headResult);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int num;
  Node *next;
}*head = NULL, *tail = NULL;

Node *create(int num){
  Node *makeNode = (Node*) malloc(sizeof(Node));
  makeNode->num = num;
  makeNode->next = NULL;
  return makeNode;
}

void pushTail(int num) {
  Node *input = create(num);
  if(!head) {
    head = tail = input;
  } else {
    tail->next = input;
    tail = input;
  }
}

void printLink() {
  Node *temp = head;
  while(temp) {
    printf("%d " , temp->num);
    temp = temp->next;
  }
}

void printMid() {
  Node *temp = head;
  int count = 0;
  while(temp) {
    count++;
    temp = temp->next;
  }
  int mid = count/2 + 1;

  temp = head;
  while(temp && mid != 1) { 
    temp = temp->next;
    mid--;
  }
  
  printf("Mid Element is %d\n",temp->num);
  
}
int main() {
  // pushTail(3);  
  // pushTail(2);  
  // pushTail(1);  
  pushTail(4);  
  pushTail(5);
  pushTail(5);
  printMid();
  return 0;
}
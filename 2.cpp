#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int num;
  int flag;
  Node *next;
}*head = NULL, *tail = NULL;

Node *create(int num){
  Node *makeNode = (Node*) malloc(sizeof(Node));
  makeNode->num = num;
  makeNode->flag = 0;
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

int checkCycle() {
  Node *temp = head;
  while(temp) {

    temp->flag++;
    if(temp->flag > 1) {
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

int main() {
  pushTail(5);  
  pushTail(4);  
  

  // Node *temp = head->next;
  // head->next->next = temp;
  int result = checkCycle();
  if(result == 1) {
    printf("Cycle Found\n");
  }
  else {
    printf("No Cycle Found\n");
  }
  return 0;
}


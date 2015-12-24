#include<stdio.h>
#include<stdlib.h>

// Declaring structure for our linked list node.
struct node {
  int data;
  struct node *link;
};

// Prototypes functions.
struct node* insert(struct node* head, int data);
struct node* print(struct node* head);
struct node* search(struct node* head, int val);

void main(void) {

// Create head pointer and assign it to null since the list is empty for now.
struct node *head;
head = NULL;

// add a node manually to out linked list.
struct node* firstnode = (struct node*)malloc(sizeof(struct node));
firstnode->data = 10;
firstnode->link = NULL;
// head pointer now points to firstnode.
head = firstnode;

// insert other nodes using the insert function.
insert(head, 14);
insert(head, 24);
insert(head, 414);

// print all the data in each node.
print(head);

// search for specific data in the linked list.
search(head, 414);

}

struct node* insert(struct node* head, int data) {
  struct node* tmp = head;
  while (tmp->link != NULL) {
    tmp = tmp->link;
  }
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  tmp->link = newnode;
  newnode->data = data;
  newnode->link = NULL;
  return newnode;
}


struct node* print(struct node* head) {
  struct node* tmp = head;
  int i = 0;
  while (tmp->link != NULL) {
    printf("data on node %i: %d.\n", ++i, tmp->data);
    tmp = tmp->link;
  }
    printf("data on node %i: %d.\n", ++i, tmp->data);
}

struct node* search(struct node* head, int val) {
  int i = 0;
  struct node* tmp = head;
  while (tmp->link != NULL) {
    if (tmp->data == val) {
      printf("Value %i in node: %i.\n", val, i);
      break;
    }
    else {
      tmp = tmp->link;
      i++;
    }
  }
  if (tmp->data == val) {
    printf("Value %i in node: %i.\n", val, i);
  }
  else {
    printf("Value %i not found!.\n", val);
  }
}

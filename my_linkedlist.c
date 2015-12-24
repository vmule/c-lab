#include<stdio.h>
#include<stdlib.h>

// Declaring structure for our linked list node.
struct node {
  int data;
  struct node *next;
};

// Prototypes functions.
struct node* insert(struct node* head, int data);
struct node* print(struct node* head);
struct node* search(struct node* head, int val);

int main(void) {

// Create head pointer and assign it to null since the list is empty for now.
struct node *head;
head = NULL;

// add a node manually to out linked list.
struct node* firstnode = (struct node*)malloc(sizeof(struct node));
firstnode->data = 10;
firstnode->next = NULL;
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

return 0;
}

struct node* insert(struct node* head, int data) {
  struct node* current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  current->next = newnode;
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}


struct node* print(struct node* head) {
  struct node* current = head;
  int i = 0;
  while (current->next != NULL) {
    printf("data on node %i: %d.\n", ++i, current->data);
    current = current->next;
  }
    printf("data on node %i: %d.\n", ++i, current->data);
}

struct node* search(struct node* head, int data) {
  int i = 0;
  struct node* current = head;
  while (current->next != NULL) {
    if (current->data == data) {
      printf("Value %i in node: %i.\n", data, i);
      break;
    }
    else {
      current = current->next;
      i++;
    }
  }
  if (current->data == data) {
    printf("Value %i in node: %i.\n", data, i);
  }
  else {
    printf("Value %i not found!.\n", data);
  }
}

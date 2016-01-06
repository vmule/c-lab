// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse

/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void goToNext(Node *ptr);

void ReversePrint(Node *head) {

  struct Node* goToNext(Node *ptr);
  if (head != NULL) {
    struct Node *ptr = head;
    goToNext(ptr);
  }
}

void goToNext(Node *ptr){
  if (ptr->next != NULL) {
    goToNext(ptr->next);
  }
  printf("%i\n", ptr->data);
}

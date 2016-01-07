// https://www.hackerrank.com/challenges/reverse-a-linked-list

/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void goToNext(Node *ptr);
struct Node *newHead;

Node* Reverse(Node *head) {
  if (head != NULL && head->next != NULL ) {
    struct Node *current = head;
    goToNext(current);
    head->next = NULL;
    return newHead;
  } else {
      return head;
  }
}

void goToNext(Node *ptr){
  if ((ptr->next)->next != NULL) {
    goToNext(ptr->next);
  } else {
      newHead = ptr->next;
      newHead->next = ptr;
  }
  (ptr->next)->next = ptr;
}

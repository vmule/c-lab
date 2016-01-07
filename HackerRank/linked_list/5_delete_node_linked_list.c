// https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list

/*
  Delete Node at a given position in a linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position){

 if (head == NULL) {
   return NULL;
 }

  if (0 == position) {
    return head->next;
  }

  int i;
  struct Node *current = head;

  for (i = 0; i < (position -1 ); i++) {
    current = current->next;
  }
  current->next = (current->next)->next;
  return head;
}

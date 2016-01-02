// https://www.hackerrank.com/challenges/compare-two-linked-lists

/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not.
  Node is defined as:
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

int CompareLists(Node *headA, Node* headB){
  if (headA != headB) {
    while (headA != NULL && headB != NULL) {
      if (headA->data == headB->data) {
        headA = headA->next;
        headB = headB->next;
      } else {
          return 0;
      }
    }
    if (headA != NULL && headB == NULL) {
      return 0;
      }
    if (headA == NULL && headB != NULL) {
      return 0;
    }
  }
  return 1;
}

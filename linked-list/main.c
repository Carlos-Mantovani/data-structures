#include <stdio.h>
#include "list.h"

int main() {
  struct LinkedList list1 = { .head = NULL, .tail = NULL};
  struct LinkedList list2 = { .head = NULL, .tail = NULL};

  insertNodeAtStart(&list1, 1);
  insertNodeAtEnd(&list1, 2);

  insertNodeAtStart(&list2, 10);
  insertNodeAtEnd(&list2, 32);
  insertNodeAtStart(&list2, 13);

  printList(list1.head);
  printList(list2.head);
  
  return 0;
}

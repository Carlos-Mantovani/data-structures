#include <stdint.h>

struct Node {
  uint8_t data;
  struct Node *prev;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
  struct Node *tail;
};

struct Node *createNode(uint8_t data);
void insertNodeAtStart(struct LinkedList *list, uint8_t data);
void insertNodeAtEnd(struct LinkedList *list, uint8_t data);
void printList(struct Node *head);



#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*struct Node {
  uint8_t data;
  struct Node *prev;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
  struct Node *tail;
};
*/

struct Node *createNode(uint8_t data) {
  struct Node *node = (struct Node *) calloc(1, sizeof(struct Node));
  if (node == NULL) {
    printf("Failed to alocate memory\n");
    exit(1);
  }
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  return node;
}


void insertNodeAtStart(struct LinkedList *list, uint8_t data) {
  struct Node *node = createNode(data);
  if (list->head == NULL) {
    list->head = list->tail = node;
  } else {
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
  }
}

void insertNodeAtEnd(struct LinkedList *list, uint8_t data) {
  struct Node *node = createNode(data);
  if (list->head == NULL) {
    list->head = list->tail = node;
  } else {
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
  }
}

void printList(struct Node *head) {
  while(head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

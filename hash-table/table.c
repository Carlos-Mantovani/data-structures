#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
/*
#define TABLE_SIZE 100

struct Node {
  char *key;
  char *data;
  struct Node *next;
};

struct Hash {
  struct Node *list[TABLE_SIZE];
};
*/

unsigned int hashCode(char *key) {
  unsigned long hash = 5381;
  unsigned int c;
  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + c; //hash * 33 + c
  }
  return hash % TABLE_SIZE;
}

struct Node *createNode(char *key, char *data) {
  struct Node *node = (struct Node*) calloc(1 , sizeof(struct Node));
  node->key = key;
  node->data = data;

  return node;
}

char *search(struct Hash *hash, char *key) {
  unsigned int index = hashCode(key);
  struct Node *node = hash->list[index];
  while (node) {
    if (strcmp(node->key, key) == 0) {
      return node->data;
    }
    node = node->next;
  }
  return "";
}

void insertNode(struct Hash *hash, char *key, char *data) {
  unsigned int index = hashCode(key);
  struct Node *node = hash->list[index];
  if (node == NULL) {
    hash->list[index] = createNode(key, data);
  } else {
    while (node) {
      if (node->next == NULL) {
        node->next = createNode(key, data);
        break;
      }
      node = node->next;
    }
  }
}





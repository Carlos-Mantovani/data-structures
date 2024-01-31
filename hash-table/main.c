#include <stdio.h>
#include <stdlib.h>
#include "table.h"

int main() {
  struct Hash *hash = (struct Hash*) malloc(sizeof(struct Hash));
  insertNode(hash, "name", "Carlos");
  insertNode(hash, "country", "Brazil");
  insertNode(hash, "OS", "Arch Linux");

  printf("name: %s\n", search(hash, "name"));
  printf("country: %s\n", search(hash, "country"));
  printf("OS: %s\n", search(hash, "OS"));

}


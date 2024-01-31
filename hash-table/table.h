#define TABLE_SIZE 100

struct Node {
  char *key;
  char *data;
  struct Node *next;
};

struct Hash {
  struct Node *list[TABLE_SIZE];
};

unsigned int hashCode(char *key);
struct Node *createNode(char *key, char *data);
char *search(struct Hash *hash, char *key);
void insertNode(struct Hash *hash, char *key, char *data);

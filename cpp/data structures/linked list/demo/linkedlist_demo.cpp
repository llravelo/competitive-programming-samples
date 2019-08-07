#include "../linkedlist.h"
#include <cstdio>

int main() {
  LinkedList<int> *list = new LinkedList<int>();

  list->insertNode(3);
  list->insertNode(1);
  list->insertNode(2);
  list->insertNode(4);

  struct node<int> *root = list->getRoot();

  while (root != nullptr) {
    printf("value: %d\n", root->val);
    root = root->next;
  }

  return 0;
}

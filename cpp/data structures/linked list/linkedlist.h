// A linked-list is a dynamic list of elements, with pointers to the next
// It has the advantage of dynamic memory allocation
// increasing or decreasing in size as needed unlike arrays with a predefined
// size However, It comes at a cost of not being cache friendly So sequential
// traversal will have additional overhead compared to arrays

template <class type> struct node {
  type val;
  struct node *next;
};

template <class type> struct doubly_node {
  type val;
  struct doubly_node *prev;
  struct doubly_node *next;
};

// Basic Operations: Insert, Search, Delete
// Singly Linked List

template <class type> class LinkedList {
private:
  struct node<type> *root;

public:
  LinkedList() { root = nullptr; }

  struct node<type> *getRoot() {
    return root;
  }

  void
  insertNode(type value) {
    struct node<type> *temp = new struct node<type>;
    temp->val = value;
    temp->next = nullptr;

    if (root == nullptr) {
      root = temp;
      return;
    }

    struct node<type> *cur = root;
    if (root->val > temp->val) {
      temp->next = root;
      root = temp;
      return;
    }

    while (cur->next != nullptr) {
      if (cur->next->val > temp->val)
        break;
      cur = cur->next;
    }

    temp->next = cur->next;
    cur->next = temp;
  }

  struct node<type> *searchNode(type value) {
    struct node<type> *cur = root;

    while (cur != nullptr) {
      if (cur->val == value)
        break;
      cur = cur->next;
    }

    return cur;
  }

  void
  deleteNode(type value) {
    if (root == nullptr)
      return;

    struct node<type> *cur = root;
    struct node<type> *prev = cur;

    while (cur != nullptr) {
      if (cur->val == value) {
        if (cur == root)
          root = root->next;

        prev->next = cur->next;
        delete cur;
        return;
      }
      prev = cur;
      cur = cur->next;
    }
  }
};

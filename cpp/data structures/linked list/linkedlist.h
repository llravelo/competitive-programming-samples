// A linked-list is a dynamic list of elements, with pointers to the next
// It has the advantage of dynamic memory allocation
// increasing or decreasing in size as needed unlike arrays with a predefined size
// However, It comes at a cost of not being cache friendly
// So sequential traversal will have additional overhead compared to arrays

template <class elementType>
struct linkedlist {
    elementType val;
    struct linkedlist* next;
};

template <class elementType>
struct doubly_linkedlist {
    elementType val;
    struct double_linkedlist* prev;
    struct double_linkedlist* next;
};

template <class elementType>
struct linkedlist<elementType>* search_node(struct linkedlist<elementType>* root, elementType value)
{
    
}

template <class elementType>
void delete_node(struct linkedlist<elementType>* root, elementType value)
{
    if (root == nullptr) return;

    struct linkedlist<elementType> cur = root;
    if (cur->val == value) {
        delete root;
        root = nullptr;

        return;
    }

    struct linkedlist<elementType> prev = root;
    cur = root->next;

    while (cur != nullptr)
    {
        if (cur->val == value)
        {
            prev->next = cur->next;
            delete cur;

            return;
        }

        prev = cur;
        cur = cur->next;
    }
}
// Insertion sort
// Using function templates to use any data type

template <class type> void sort(type *arr, int len) {
  int elemInHand;
  int i, j;

  for (i = 0; i < len; i++) {
    elemInHand = arr[i];
    for (j = i; j > 0; j--) {
      if (elemInHand < arr[j - 1])
        arr[j] = arr[j - 1];
      else
        break;
    }
    arr[j] = elemInHand;
  }
}

template <class type>
void sort(type *arr, int len, bool (*compare)(type, type)) {
  int elemInHand;
  int i, j;

  for (i = 0; i < len; i++) {
    elemInHand = arr[i];
    for (j = i; j > 0; j--) {
      if (compare(elemInHand, arr[j - 1]))
        arr[j] = arr[j - 1];
      else
        break;
    }
    arr[j] = elemInHand;
  }
}
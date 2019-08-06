// Merge sort
// Using function templates to use any data type

template <class arrayType>
void merge(arrayType* arr, arrayType* temp, int left, int middle, int right, bool (*cb)(arrayType, arrayType))
{
    int leftIndex;
    int rightIndex;
    int arrIndex;

    // Copy left and right array to temp
    for(leftIndex=left; leftIndex<=middle; leftIndex++) temp[leftIndex] = arr[leftIndex];
    for(rightIndex=middle+1; rightIndex<=right; rightIndex++) temp[rightIndex] = arr[rightIndex];

    leftIndex = left;
    rightIndex = middle+1;
    arrIndex = left;

    // For each element in subarray, fill-in according to comparison function
    while(leftIndex<=middle && rightIndex<=right)
    {
        if (cb(temp[leftIndex], temp[rightIndex])) arr[arrIndex++] = temp[leftIndex++];
        else arr[arrIndex++] = temp[rightIndex++];
    }

    // Fill in remaining elements
    while(leftIndex<=middle) arr[arrIndex++] = temp[leftIndex++];
    while(rightIndex<=right) arr[arrIndex++] = temp[rightIndex++];
}


template <class arrayType>
void divideArray(arrayType* arr, arrayType* temp, int left, int right, bool (*cb)(arrayType, arrayType))
{
    // Divide into subproblems
    if (left >= right) return;

    int middle = (left + right) / 2;
    divideArray(arr, temp, left, middle, cb);
    divideArray(arr, temp, middle+1, right, cb);

    merge(arr, temp, left, middle, right, cb);
}

template <class arrayType>
bool compareClassic(arrayType left, arrayType right)
{
    // less than or EQUAL for stable sort
    return left <= right;
}

template <class arrayType>
void sort(arrayType* arr, int len)
{
    arrayType* temp = new arrayType[len];
    divideArray(arr, temp, 0, len-1, compareClassic);
}

template <class arrayType>
void sort(arrayType* arr, int len, bool (*compare)(arrayType, arrayType))
{
    arrayType* temp = new arrayType[len];
    divideArray(arr, temp, 0, len-1, compare);
    delete temp;
}

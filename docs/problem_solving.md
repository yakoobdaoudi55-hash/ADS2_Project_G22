## Function: insertAt

### Problem Understanding (An Example)

* Input:  arr\[] — the array, \*size — current element count,
index — position to insert at, value — element to insert
* Output: returns 0 on success, -1 on error; modifies arr\[] and \*size
* Edge cases: index out of bounds, array full (size >= MAX\_1D)

### Algorithm (Simple steps only)

1. Check that index is within \[0, \*size] and size < MAX\_1D
2. Shift all elements from position index rightward by one slot
3. Place value at arr\[index] and increment \*size



## Function: printArray

### Problem Understanding

* Input:
* Output:

### Algorithm


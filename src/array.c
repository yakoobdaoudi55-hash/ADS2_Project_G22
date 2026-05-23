
#include "../include/array.h"      // It represent the path towards my header (library)
#include <stdio.h>
#include <stdlib.h>




/* Initialize: set size to 0 — array is logically empty */ 
void initArray(int arr[], int* size) {
    *size = 0;  //set size to zero ampty array 
}




//Print in [a, b, c] format */
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", "); // for setting comas on display
    }
    printf("]\n");
}

   
   
   
   
/* Insert value at index — shift elements right first */
int insertAt(int *arr, int* size, int index, int value) {
    if (index < 0 || index > *size) return -1;  // invalid index
    if (*size >= MAX_1D) return -1;             // array full
    int i;
    for (i = *size; i > index; i--)
        arr[i] = arr[i - 1]; //shift element to the right 

    arr[index] = value;  //insert value
    *size=*size+1; // expend size
    return 0;
}





int deleteAt(int arr[], int* size, int index) {
    if(index < 0 || index >= *size) return -1; // invalis value

    for(int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1]; // shift left
    }

    *size=*size-1;
    return 0;
}
    
    
    
int linearSearch(int arr[], int size, int value) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == value){ //search for value
        	return i; // show the index of value
		} 
    }
    return -1; // when value deosnt found
}


//array should be orderd so we should call bubbleSort(int arr[], int size) first 
int BinarySearch(int arr[], int size, int value) {
    int low = 0;
    int high = size - 1;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == value)
            return mid;

        else if(value < arr[mid]) // search in left 
            high = mid - 1; // the hight is the element before mid

        else // search in right
            low = mid + 1;// the hight is the element after mid
    }

    return -1; //if  doesnt exist 

    
    for(int i = 0; i < size; i++) {
        if(arr[i] == value){ //search for value
        	return i; // show the index of value
		} 
    }
    return -1; // when value deosnt found
}





void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {// loop for reputations ;  used size-1  there is no elemnt to compare the last with 
    	int swapped=0;
        for(int j = 0; j < size - i - 1; j++) { // loop for comparing use -i to skip the allready ordered element
            if(arr[j] > arr[j + 1]) {  
                int temp = arr[j]; // variable temprary
                arr[j] = arr[j + 1]; // SWAP element YWELI li ba3dou 
                arr[j + 1] = temp; //li ba3dou yweli l element
            }
            
        }
        
    if(swapped == 0) break; //stop the loop

    }
}







int findMax(int arr[], int size) {
    int max = arr[0]; // we asuume it the first element
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) max = arr[i]; // IF there is a bigger one we considret max 
    }
    return max;
}

int findMin(int arr[], int size) {
    int min = arr[0]; // we asuume it the first element
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) min = arr[i]; // IF there is smaller one we considret min 
    }
    return min;
}







int sumArray(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum =sum+ arr[i]; // calculating 
    }
    return sum; //return the sum
}



void reverseArray(int arr[], int size) {
    for(int i = 0; i < size / 2; i++) { // split size to order it coreecty if we didnt the array return to the same as first 
        int temp = arr[i];
        arr[i] = arr[size - 1 - i]; //swapping
        arr[size - 1 - i] = temp;
    }
}

void rotateLeft(int arr[], int size, int k) {
    if(size == 0) return;

    k = k % size;  // to skip unnecessary rotations when k is greater than size

    for(int i = 0; i < k; i++) {
        int first = arr[0]; // store first element
        for(int j = 0; j < size - 1; j++) { 
            arr[j] = arr[j + 1];//move element left not a swap
        }

        arr[size - 1] = first; // first becomes last
    }
}
void mergeSortedArrays(int a[], int na, int b[], int nb, int mer[]) {
    int i = 0, j = 0, k = 0;

    // merge arrays
    while(i < na && j < nb) { //continue while there still element in a or b
        if(a[i] <= b[j]) {
            mer[k++] = a[i]; //PUT a IN OUT THEN ADD 1 to k
            i++;
        } else {
            mer[k++] = b[j];
            j++;
        }
    }

    while(i < na) { //if they still elemenyt in a we take it kima rahi 
        mer[k++] = a[i];
        i++;

    }

    
    while(j < nb) {//if they still elemenyt in b we take it kima rahi 
        mer[k++] = b[j];
        j++;

    }
}

double averageArray(int arr[], int size){
	double sum=0;
	if (size==0) { //if ampty return 0
		return 0.0;
	}
	for (int i=0 ;i<size ;i++ ){
		sum=sum+arr[i]; //calculate the sum
	}
    return (double)sum / size; // return the average
	}
	
	
	
	// orderring by chossing the smallest element and put it first
void selectionSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {// size -1 the last element is orderd by default

        int minIndex = i;

        for(int j = i + 1; j < size; j++) {//start from index 1
            if(arr[j] < arr[minIndex]) { //if the second element is smaller 
                minIndex = j;  // the minindex change to j 
            }
        }

        int temp = arr[i];  //swap the first with second element 
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}


// Take one element and insert it into its correct position in the sorted part
void insertionSort(int arr[], int size) {
    for(int i = 1; i < size; i++) {

        int key = arr[i]; // choose element key with index 1 or the next after j
        int j = i - 1; //index j is i-1 for the prevous element

        while(j >= 0 && arr[j] > key) { // comaprision if true we swap 
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


void mergesort(int arr[], int left, int right) {
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    
    int n1 = mid - left + 1; // get the left part array -1 to avoid mid
    int n2 = right - mid; // get right part array 

    int L[n1], R[n2]; // L containse the left part    R contains the right part

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i]; // get the values of left part 

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];// get the values of right part +1 to avoid mid

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {// there still value on l and R
        if(L[i] <= R[j]) { //if L value is smaller 
            arr[k] = L[i]; //put it in arr the result
            i++; //compare same R value with next L value
        } else {//if L is smaller
            arr[k] = R[j]; //put it in arr the result
            j++;//compare same R value with next L value
        }
        k++;
    }

    while(i < n1) // rest of L
        arr[k++] = L[i++];

    while(j < n2) // the rest of R
        arr[k++] = R[j++];
}
// using recursion and function inside functions 
void mergeSort(int arr[], int left, int right) {

    if(left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        //merge(arr, left, mid, right);
    }
}
void quickSort(int arr[], int low, int high) {

    if(low < high) {

        int pivot = arr[high]; //last element as pivot
        int i = low - 1;

        // partition
        for(int j = low; j < high; j++) {

            if(arr[j] < pivot) {// when there is smaller than pivot
                i++;// move on all element

                int temp = arr[i];//swap to the left
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp; //pivot in middle

        int pi = i + 1;

        // recursion
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//2D Static Matrices

void PrintMatrix( int m[][MAX_COLS], int rows, int cols) {
    for(int i = 0; i < rows; i++) {//Loop for rows 
        for(int j = 0; j < cols; j++) {//loop for cols
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
}

void AddMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int S[][MAX_COLS], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            S[i][j] = a[i][j] + b[i][j];// calculate the sum
        }
    }
}

void TransposeMatrix(int m[][MAX_COLS], int rows, int cols, int out[][MAX_COLS]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            out[j][i] = m[i][j]; // tranporting with swap cols with rows
        }
    }
}

void InitMatrix(int m[][MAX_COLS], int* rows, int* cols) {
    // reading diamentions
    printf("Enter number of rows: ");
    scanf("%d", rows);

    printf("Enter number of cols: ");
    scanf("%d", cols);

    // chack if validate
    if(*rows > MAX_ROWS || *cols > MAX_COLS || *rows <= 0 || *cols <= 0) {
        printf("Invalid size!\n");
        *rows = 0;
        *cols = 0;
        return;
    }

    // reading element of matrix
    printf("Enter elements:\n");
    for(int i = 0; i < *rows; i++) {
        for(int j = 0; j < *cols; j++) {
            scanf("%d", &m[i][j]); //scan element put it in adress
        }
    }
}
void MultiplyMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int n) {
   

    // MULTIPLICATION
    for(int i = 0; i < n; i++) { // ROWS
        for(int j = 0; j < n; j++) {//COLOMS
        int S[50][50];
            for(int k = 0; k < n; k++) {//
                S[i][j] = S[i][j]+a[i][k] * b[k][j];// MULTIPLY COLOM BY ROW THEN SUM CZ IT IS 2D 
            }
        }
    }
}

int sumDiagonal(int m[][MAX_COLS], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += m[i][i];//only diagnol elements when 2;2 or 1;1 ..
    }
    return sum;
}

int sumAntiDiagonal(int m[][MAX_COLS], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += m[i][n - 1 - i]; // antidiagnol elements 
    }
    return sum;
}
int isSymmetric(int m[][MAX_COLS], int n) {//same velues upper and below the diagnol 

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {

            if(m[i][j] != m[j][i]) {
                return 0; // NOT symmetric
            }
        }
    }

    return 1; // symmetric
}
void sortRows(int m[][MAX_COLS], int rows, int cols) {
    for(int i = 0; i < rows; i++) {//for every row

        // bubble sort FOr every row
        for(int j = 0; j < cols - 1; j++) {
            for(int k = 0; k < cols - j - 1; k++) {// elment of the row 
                if(m[i][k] > m[i][k + 1]) {//IF THERE is a smaller inside the row
                    int temp = m[i][k];
                    m[i][k] = m[i][k + 1];
                    m[i][k + 1] = temp; //swapping
                }
            }
        }

    }
}

// Dynamic Arrays
int* createDynamicArray(int capacity) {
    int* arr = (int*) malloc(capacity * sizeof(int));// capasity for num of element  malloc a place in memory the rest calculate size we need
    if(arr == NULL) { //if there no memory 
        printf("Memory allocation failed\n");
        return NULL;
    }
    return arr;
}

void fillArray(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); // reading elements
    }
}

int* resizeArray(int* arr, int newCapacity) {
    int* newArr = (int*) realloc(arr, newCapacity * sizeof(int)); //the new size 
    if(newArr == NULL) { //
        printf("Resize failed\n");
        return NULL;
    }
    return newArr;
}

void freeArray(int* arr) {
    free(arr); // make it vide 
}

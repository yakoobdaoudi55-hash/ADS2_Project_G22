#include <stdio.h>
#include "include/array.h"
 #include "include/linked_list.h" 
#include "include/stack.h" 
#include "include/queue.h"
 #include "include/file_utils.h"
 #include "include/string_utils.h"
void arrayMenu() {

    int choice,sub;
    int arr[MAX_1D];
    int size = 0;
    int value, index, k;
    int a[MAX_ROWS][MAX_COLS], b[MAX_ROWS][MAX_COLS], r[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;
    int *dArr = NULL, capacity = 0;




    do {
    	printf("\n===== MAIN MENU =====\n");
        printf("1. 1D Array\n");
        printf("2. 2D Matrix\n");
        printf("3. Dynamic Array\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        	// ================= 1D Array =================
            case 1:
            	printf("\n=== ARRAY MENU ===\n");
                printf("1. Insert element\n");
                printf("2. Delete element\n");
                printf("3. Linear Search\n");
                printf("4. Binary Search\n");
                printf("5. Display\n");
                printf("6. Bubble Sort\n");
                printf("7. Selection Sort\n");
                printf("8. Insertion Sort\n");
                printf("9. Merge Sort\n");
                printf("10. Quick Sort\n");
                printf("11. Find Max\n");
                printf("12. Find Min\n");
                printf("13. Sum\n");
                printf("14. Average\n");
                printf("15. Reverse\n");
                printf("16. Rotate Left\n");
                printf("0. Back\n");
                printf("Choice: ");

    
    
    
                scanf("%d", &sub);
                switch(sub) {
                
        case 1:
            printf("Index and value: ");
            scanf("%d %d", &index, &value);
            insertAt(arr, &size, index, value);
            break;

        case 2:
            printf("Index: ");
            scanf("%d", &index);
            deleteAt(arr, &size, index);
            break;

        case 3:
            printf("Value: ");
            scanf("%d", &value);
            printf("Index = %d\n", linearSearch(arr, size, value));
            break;

        case 4:
            bubbleSort(arr, size); // لازم يكون مرتب
            printf("Value: ");
            scanf("%d", &value);
            printf("Index = %d\n", binarySearch(arr, size, value));
            break;

        case 5:
            printArray(arr, size);
            break;

        case 6:
            bubbleSort(arr, size);
            break;

        case 7:
            selectionSort(arr, size);
            break;

        case 8:
            insertionSort(arr, size);
            break;

        case 9:
            mergeSort(arr, 0, size - 1);
            break;

        case 10:
            quickSort(arr, 0, size - 1);
            break;

        case 11:
            printf("Max = %d\n", findMax(arr, size));
            break;

        case 12:
            printf("Min = %d\n", findMin(arr, size));
            break;

        case 13:
            printf("Sum = %d\n", sumArray(arr, size));
            break;

        case 14:
            printf("Average = %.2f\n", averageArray(arr, size));
            break;

        case 15:
            reverseArray(arr, size);
            break;

        case 16:
            printf("Enter k: ");
            scanf("%d", &k);
            rotateLeft(arr, size, k);
            break;

        case 0:
            printf("Back to main menu...\n");
            break;

        default:
            printf("Invalid choice\n");
            
        }
        break;

        
        
        
        
        
        
        	 // ================= 2D MATRIX =================
        case 2:
            printf("\n--- MATRIX ---\n");
            printf("1.Init 2.Print 3.Transpose\n");
            printf("4.Add 5.Multiply 6.Symmetric\n");
            scanf("%d", &sub);

            switch(sub) {

            case 1:
                initMatrix(a, &rows, &cols);
                break;

            case 2:
                printMatrix(a, rows, cols);
                break;

            case 3:
                transposeMatrix(a, rows, cols, r);
                printMatrix(r, cols, rows);
                break;

            case 4:
                printf("Enter matrix B:\n");
                initMatrix(b, &rows, &cols);
                addMatrices(a, b, r, rows, cols);
                printMatrix(r, rows, cols);
                break;

            case 5:
                multiplyMatrices(a, b, r, rows);
                printMatrix(r, rows, cols);
                break;

            case 6:
                if(isSymmetric(a, rows))
                    printf("Symmetric\n");
                else
                    printf("Not Symmetric\n");
                break;
            }

            break;
            
            
            
            
            
            

        // ================= DYNAMIC ARRAY =================
        case 3:
            printf("\n--- DYNAMIC ARRAY ---\n");
            printf("1.Create 2.Fill 3.Resize 4.Free\n");
            scanf("%d", &sub);

            switch(sub) {

            case 1:
                scanf("%d", &capacity);
                dArr = createDynamicArray(capacity);
                break;

            case 2:
                fillArray(dArr, capacity);
                break;

            case 3:
                scanf("%d", &capacity);
                dArr = resizeArray(dArr, capacity);
                break;

            case 4:
                freeArray(dArr);
                dArr = NULL;
                break;
            }

            break;
        }
    } while(choice != 0);
}
int main() {
    int choice;
    do {
        printf("\n=== ADS2 PROJECT DEMO ===\n");
        printf("1. Arrays\n2. Linked Lists\n 3. Stacks\n"
               "4. Queues\n 5. File Handling\n 6. String Utils\n 0. Exit\n Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: arrayMenu(); break;
            /* ... */
        }
    } while (choice != 0);
    return 0;
}

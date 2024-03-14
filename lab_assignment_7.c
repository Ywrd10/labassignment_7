#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

typedef struct element {
    int data;
    int numSwaps;
} element;


element* createArray(int values[]) {
    element *arr = (element*)malloc(SIZE * sizeof(element));
    for (int i = 0; i < SIZE; i++) {
        arr[i].data = values[i];
        arr[i].numSwaps = 0;
    }
    return arr;
}


void printSwaps(element *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i].data, arr[i].numSwaps);
    }
    int totalSwaps = 0;
    for (int i = 0; i < n; i++) {
        totalSwaps += arr[i].numSwaps;
    }
    printf("%d\n", totalSwaps/2); 
}


void bubbleSort(element *arr, int n) {
    int i, j, temp,temp2;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].data > arr[j + 1].data) {
                arr[j].numSwaps++;
                arr[j + 1].numSwaps++;
                temp2=arr[j].numSwaps;
                arr[j].numSwaps=arr[j+1].numSwaps;
                arr[j+1].numSwaps=temp2;
                temp = arr[j].data;
                arr[j].data = arr[j + 1].data;
                arr[j + 1].data = temp;
            }
        }
    }
}


void selectionSort(element *arr, int n) {
    int minIdx, temp,temp2;
    for (int i = 0; i < n - 1; i++) {
        minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].data <= arr[minIdx].data) {
                minIdx = j;
            }
        }
        if(i!=minIdx){
            arr[i].numSwaps++;
            arr[minIdx].numSwaps++;
            temp2=arr[i].numSwaps;
            arr[i].numSwaps=arr[minIdx].numSwaps;
            arr[minIdx].numSwaps=temp2;
        }
        temp = arr[i].data;
        arr[i].data = arr[minIdx].data;
        arr[minIdx].data = temp;
    }
}

int main() {
    int arr1[SIZE] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[SIZE] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    element *elements1 = createArray(arr1);
    element *elements2 = createArray(arr2);


    bubbleSort(elements1, SIZE);
    printf("array1 bubble sort:\n");
    printSwaps(elements1, SIZE);

    bubbleSort(elements2, SIZE);
    printf("\narray2 bubble sort:\n");
    printSwaps(elements2, SIZE);


    free(elements1);
    free(elements2);


    elements1 = createArray(arr1);
    elements2 = createArray(arr2);

    selectionSort(elements1, SIZE);
    printf("\narray1 selection sort:\n");
    printSwaps(elements1, SIZE);

    selectionSort(elements2, SIZE);
    printf("\narray2 selection sort:\n");
    printSwaps(elements2, SIZE);


    free(elements1);
    free(elements2);

    return 0;
}

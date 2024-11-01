#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maxGroupSize(int X, int Y, int A[]) {
    // Step 1: Sort the array
    qsort(A, X, sizeof(int), compare);
    
    int maxSize = 1;  // Minimum group size is 1
    int currentSize = 1;

    // Step 2: Iterate through sorted magnets
    for (int i = 1; i < X; i++) {
        if (A[i] - A[i - 1] >= Y) {
            currentSize++;  // Add to the current group
        } else {
            // Check if this is the largest group
            if (currentSize > maxSize) {
                maxSize = currentSize;
            }
            currentSize = 1;  // Reset for new group
        }
    }
    
    // Final check after the loop
    if (currentSize > maxSize) {
        maxSize = currentSize;
    }
    
    return maxSize;
}

int main() {
    int X = 12;
    int Y = 3;
    int A[] = {1, 5, 6, 1, 8, 3, 12, 2, 13, 7, 9, 11};
    
    int result = maxGroupSize(X, Y, A);
    printf("The maximum group size is: %d\n", result);
    
    return 0;

}

#include <stdio.h>

int linear_search(int target, int arr[]);

int main(int argc, char const *argv[])
{
    // Declaring an array of length 8
    int array[] = {0, 3, 5, 6, 4, 1, 7, 10};

    // Declaring a target that is to be searched for in the array. Currently it is 10, but can be modified.
    int target = 10;

    // A print statement that is a formatted string of 1) the target that is to be found in the array,
    // and 2) if it is found, the index at which it is situated.
    printf("Linear Search: Found %d at index %d", target, linear_search(target, array));
    
    // End function main by returning 0
    return 0;
}

/* Linear search method: checks linearly of the existence of a target number in an array of numbers,
 * and returns the index where it is located, if present, otherwise -1 if not present in the array. ***/

int linear_search(int target, int arr[]) {
    /** Simple for-loop iterating through the contents of the array in an increasing manner, and checking for if the number at that index "i", 
     * is the target.*/
    for (int i = 0; i<(sizeof(arr)); i++) {
        if (target == arr[i]) {
            return i;
        }
    }

    // After going through the loop and not finding the number, the "target" is not present in the array, hence return -1 in that case.
    return -1;
}
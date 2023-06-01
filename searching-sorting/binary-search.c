#include <stdio.h>

/**
 * Binary Searching Algorithm, that restricts the index bounds of where the number is searched for, based on if it greater than, or less than
 * certain numbers in an ordered list.
 * 
 * It is a prerequisite for the list to be sorted in ascending order before conducting binary search.
*/
int binary_search(int target, int arr[], int low, int hi) {
    /** If low ends up being greater than hi, this means that the array has been halved to the point where the number was not to be found in
     * any of the divided sections of the array.
    */
    if (low > hi) { return -1; }
    /** Calculating the midpoint of the array, to progressively halve the region of interest of the array, where the target number may be located. */
    int mid = (low+hi)/2;

    /** This approach uses recursive means to search the array. 
     * First case: Target is greater than the number in the middle of the array, then the binary search method is called again, and 
     *             the right-half of the array is now examined, eliminating the left-half. The starting index is now the index after the mid,
     *             and the upper bound stays the same.
     * Second case: Target is less than the number in the middle of the array, which means it must be located in the left-side of the
     *              initial array. Hence, out of the last two params of the method call, the upper bound is now the index BEFORE the mid, and lower
     *              bound stays the same.
     * Third case: Eventually, with the recursive calls, and the consequent halving of the initial array space, at some point, the region that is examined is
     *              just of length one, and also the mid-value simultaneously. Based on previously done checks on the possible location of the number in the ascending
     *              ordered array, if the target is present in the array, it should be here, at that index. Then, the "else" signifies that the mid == target, and if it is true,
     *              return mid (index where target is located).
    */
    if (target > arr[mid]) {
        binary_search(target, arr, mid+1, hi);
    } else if (target < arr[mid]) {
        binary_search(target, arr, low, mid-1);
    } else 
        return mid;
};

int main(int argc, char const *argv[])
{
    /** Declaring an array of size 7, and setting a target to find (8) */
    int arr[] = {1, 3, 5, 6, 8, 9, 10};
    int target = 8;

    /** Printing the index of where the target is located in the array, using binary search, starting with lower & upper bounds,
     *  of 0 (first index), and the length of the array - 1. As more calls take place, the area that will be worked with, to find the 
     *  target, will reduce by 1/2 each time, constricting the location in the ordered array.
     */
    printf("%d\n", binary_search(target, arr, 0, sizeof(arr)/sizeof(int)));
    return 0;
}
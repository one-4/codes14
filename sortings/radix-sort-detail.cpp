#include <iostream>

using namespace std;

/**
 * Function to get the maximum element from the array
 *  arr - the array
 *  n - the size of the array
 * @return the maximum element
 */
/**
 * Finds the maximum value in an integer array.
 *
 *  arr The input integer array.
 *  n The number of elements in the array.
 *
 * @returns The maximum value in the array.
 */
int getMax(int arr[], int n) {     // gets the maximum element from the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/**
 * Function to perform counting sort based on significant places
 *  arr - the array to be sorted
 *  n - the size of the array
 *  exp - the significant place
 */
void countSort(int arr[], int n, int exp) {
    int output[n];    // array to store the sorted elements
    int count[10] = {0};   // array to store the count of each digit

    // Count the number of occurrences of each digit in arr[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    /*This is a part of the Radix Sort algorithm, specifically the counting sort step for a single digit. Here's a breakdown of what's happening:

arr[i]: This is the current element in the array being processed.
exp: This is the current exponent or place value being considered. For example, if we're sorting based on the ones place, exp would be 1. If we're sorting based on the tens place, exp would be 10, and so on.
(arr[i] / exp): This divides the current element by the exponent, effectively shifting the digits to the right. For example, if arr[i] is 123 and exp is 10, this would give us 12.
((arr[i] / exp) % 10): This takes the result of the previous step and computes the remainder when divided by 10. This effectively extracts the digit at the current place value. For example, if the result of the previous step is 12, this would give us 2, which is the digit in the tens place.
count[...]++: This increments the count for the extracted digit in the count array. The count array is assumed to have 10 elements, one for each digit from 0 to 9.
The net effect of this line is to count the occurrences of each digit at the current place value in the array.

For example, suppose we have the array [12, 34, 56, 78, 90] and we're sorting based on the ones place (i.e., exp is 1). The loop would iterate as follows:

i = 0, arr[i] = 12, (arr[i] / exp) % 10 = 2, so count[2]++.
i = 1, arr[i] = 34, (arr[i] / exp) % 10 = 4, so count[4]++.
i = 2, arr[i] = 56, (arr[i] / exp) % 10 = 6, so count[6]++.
i = 3, arr[i] = 78, (arr[i] / exp) % 10 = 8, so count[8]++.
i = 4, arr[i] = 90, (arr[i] / exp) % 10 = 0, so count[0]++.
After this loop, the count array would contain the counts of each digit in the ones place: [1, 0, 1, 1, 1, 1, 1, 1, 1, 0].

*/

    // Calculate the cumulative count
    for (int i = 1; i < 10; i++) {
        count[i]=count[i]+count[i-1];
        // OR count[i] += count[i-1];
    }
/*This code calculates the cumulative count of the digits in the count array. Here's a step-by-step explanation:

for (int i = 1; i < 10; i++): This loop iterates from i = 1 to i = 9, inclusive. It skips the first element of the count array (index 0).
count[i] += count[i - 1]: For each iteration, this line adds the value of the previous element (count[i - 1]) to the current element (count[i]).
The effect of this loop is to calculate the cumulative count of the digits in the count array.*/


    // Place the elements in their correct position
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted elements back to arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

/**
 * Function to perform Radix Sort
 *  arr - the array to be sorted
 *  n - the size of the array
 */
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Perform counting sort for each significant place
    for (int exp = 1; max / exp > 0; exp=exp*10) {
        countSort(arr, n, exp);
    }
}

/**
 * Function to print the array
 *  arr - the array to be printed
 *  n - the size of the array
 */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * Main function to test the radix sort
 */
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66,12,14,1,545,90,77,134,225,45,76,78,89,90,123,456,789,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Sort the array using radix sort
    radixSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}

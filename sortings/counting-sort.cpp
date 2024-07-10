#include <iostream>

using namespace std;

int getMax(int arr[], int n) {     // gets the maximum element from the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
// Function to perform Counting Sort
void countingSort(int arr[], int n, int max) {
    int count[max + 1] = {0}; // count array to store the count of each element
    int output[n]; // output array to store the sorted elements

    // Count the occurrences of each element in the input array
    // frequency array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Calculate the cumulative count
    // cumulative frequency array
    for (int i = 1; i <= max; i++) {
        count[i]=count[i]+count[i-1];
        // count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1,4,1,2,7,5,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max= getMax(arr,n);
    cout<<max<<endl;
    cout << "Original array: ";
    printArray(arr, n);

    countingSort(arr, n, max);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
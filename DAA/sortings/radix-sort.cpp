#include <iostream>

using namespace std;

// Function to get the maximum element from the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort based on significant places
void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    //frequency array
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    //cumulative frequency array
    for (int i = 1; i < 10; i++) {
        // count[i] += count[i - 1];
        count[i]=count[i]+count[i-1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
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
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"["<<i<<"] = ";
        cin>>arr[i];        
    }
    int max= getMax(arr,n);
    cout<<"max number is: "<<max <<endl;
    
    cout << "Original array: ";
    printArray(arr, n);

    radixSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
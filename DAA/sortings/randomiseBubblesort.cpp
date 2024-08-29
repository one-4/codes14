
#include<iostream>
#include<time.h>

void randomInput(int arr[], long size) {
    time_t t;
    srand((unsigned)time(&t));
    for(long i = 0; i < size; i++)
        arr[i] = rand() % 100;
}

void display(int arr[], long size) {
    std::cout << "[ ";
    for(long i = 0; i < size; i++) {
        std::cout << arr[i];
        if(i < (size - 1))
            std::cout << ", ";
    }
    std::cout << " ]\n";
}

long BubbleSort(int arr[], long size) {
    long comparison = 0;
    int flag;
    for(long i = 0; i < (size - 1); i++) {
        flag = 0;
        for(long j = 0; j < (size - i - 1); j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag++;
            }
            comparison++;
        }
        if(flag == 0)
            break;
    }
    return comparison;
}

int main() {
    long size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    int *arr = new int[size];
    randomInput(arr, size);
    std::cout << "The array is\n";
    display(arr, size);
    std::cout << "Number of comparisons in Bubble Sort is " << BubbleSort(arr, size);
    std::cout << "\nAfter sorting the array is\n";
    display(arr, size);
    delete[] arr;
    return 0;
}

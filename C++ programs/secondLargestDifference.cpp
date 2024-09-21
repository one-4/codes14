#include <iostream>
#include <limits>

int main() {
    int n;

    // Input array size
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "Array should have at least 2 elements." << std::endl;
        return 1;
    }

    int arr[n];

    // Input array elements
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Initialize smallest and second smallest
    int smallest = std::numeric_limits<int>::max();
    int second_smallest = std::numeric_limits<int>::max();
    int largest = std::numeric_limits<int>::min();
    int second_largest = std::numeric_limits<int>::min();

    // Find smallest, second smallest, largest, and second largest
    for (int i = 0; i < n; ++i) {
        // Update smallest and second smallest
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }

        // Update largest and second largest
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    // Check if we found valid second smallest and second largest
    if (second_smallest == std::numeric_limits<int>::max() || 
        second_largest == std::numeric_limits<int>::min()) {
        std::cout << "There should be at least two distinct elements." << std::endl;
        return 1;
    }

    // Calculate the difference
    int difference = second_smallest - second_largest;

    // Output the result
    std::cout << "Difference between second smallest and second largest: " << difference << std::endl;

    return 0;
}

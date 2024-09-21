#include <iostream>
#include <limits>

int main() {
    int n;

    // Take the size of the array from the user
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Array size must be positive." << std::endl;
        return 1;
    }

    int arr[n];
    
    // Initialize min and max with extreme values
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();



    // Find the smallest and largest numbers
    for (int i = 0; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Calculate the difference
    int difference = max - min;

    std::cout << "The difference between the largest and smallest numbers is: " << difference << std::endl;

    return 0;
}

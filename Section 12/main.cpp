#include <iostream>

using namespace std;

// Prototypes
void print(int const *arr, int size);
int* apply_all(const int *arr1, int size1, const int *arr2, int size2);

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};

    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

    cout << "Array 1: ";
    print(array1, array1_size);

    cout << "Array 2: ";
    print(array2, array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size { array1_size * array2_size };

    cout << "Result: ";
    print(results, results_size);

    cout << endl;

    delete[] results;
    return 0;
}

/**********************************************************

This function expects:
    arr - a pointer to an array of integers
    size - the number of integers in the array

The function loops over the elements and prints them our
as a formatted array string to display the contents.

/**********************************************************/
void print(const int *const arr, const int size) {
    cout << "[ ";

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << "]" << endl;
}

/**********************************************************

This function expects:
    arr1    - a pointer to an array of integers
    size1   - the number of integers in the array arr1
    arr2    - a pointer to an array of integers
    size2   - the number of integers in the array arr2

The function dynamically allocates a new array that is the size = size1 * size2.
Then it loops through each element of arr2 and multiplies it across all the
elements of arr1 and each product is stored in the newly created array

/**********************************************************/
int* apply_all(const int * const arr1, const int size1, const int * const arr2, int const size2) {
    auto *results = new int[size1*size2];
    int position {0};

    for (size_t i {0}; i < size2; ++i) {
        for (size_t j {0}; j < size1; ++j) {
            results[position] = arr1[j] * arr2[i];
            position++;
        }
    }

    return results;
}

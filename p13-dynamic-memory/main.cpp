/* http://www.cplusplus.com/doc/tutorial/dynamic/
 * A program that shows the usage of dynamic memory. */

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int size = 5;
    int *arr1, *arr2;

    // Use the new operator
    arr1 = new int[size];
    // If the allocation above fails, the program throws an exception
    for (int iter = 0; iter < size; iter += 1) {
        arr1[iter] = iter + 1;
    }
    cout << "main: arr1: [";
    for (int iter = 0; iter < size; iter += 1) {
        cout << arr1[iter];
        if (iter < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Use the new operator with nothrow argument
    arr2 = new (nothrow) int[size];
    // If the allocation above fails, arr2 now has the value of nullptr
    for (int iter = 0; iter < size; iter += 1) {
        arr2[iter] = iter + 1;
    }
    cout << "main: arr2: [";
    for (int iter = 0; iter < size; iter += 1) {
        cout << arr2[iter];
        if (iter < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Use the delete operator
    delete arr1;
    // The above operator is usually used to delete dynamically allocated
    // objects or dynamically allocated arrays
    cout << "main: deleted arr1" << endl;

    // Use the delete[] operator
    delete[] arr2;
    // The above operator is usually useed to delete dynamically allocated
    // arrays of dynamically allocated objects (which is equivalent to batch
    // delete operations) or to delete dynamically allocated arrays
    cout << "main: deleted[] arr2" << endl;

    // More info about delete and delete[]:
    // See: http://www.cplusplus.com/reference/new/operator%20delete/
    // See: http://www.cplusplus.com/reference/new/operator%20delete%5B%5D/

    // Delete a nullptr
    delete (int *)nullptr;
    // The above statement, as well as the delete[] nullptr statement, have no
    // side effects.
    cout << "main: deleted nullptr" << endl;

    return EXIT_SUCCESS;
}

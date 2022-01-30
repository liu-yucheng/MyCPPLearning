/* Ref: http://www.cplusplus.com/doc/tutorial/arrays 
 * A program that shows the usage of C++ arrays. */

/* Copyright 2022 Yucheng Liu. GNU GPL3 license.
 * GNU GPL3 license copy: https://www.gnu.org/licenses/gpl-3.0.txt */

#include <array>
#include <iostream>

using namespace std;

void printArr(int[], int);
void editArr(int[], int, int);

int main(int argc, char **argv) {
    // Initialize an array
    int arr1[5] = {1, 2, 3, 4, 5};
    // Print array elements
    cout << "main: arr1: [";
    for (int iter = 0; iter < 5; iter += 1) {
        cout << arr1[iter];
        if (iter < 4) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Partially initialize an array
    int arr2[5] = {1, 2, 3};
    cout << "main: arr2: [";
    for (int iter = 0; iter < 5; iter += 1) {
        cout << arr2[iter];
        if (iter < 4) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Trivially initialize an array
    int arr3[5] = {};
    cout << "main: arr3: [";
    for (int iter = 0; iter < 5; iter += 1) {
        cout << arr3[iter];
        if (iter < 4) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Declare an uninitialized array
    int arr4[5];
    cout << "main: arr4: [";
    for (int iter = 0; iter < 5; iter += 1) {
        cout << arr4[iter];
        if (iter < 4) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Initialize a 2D array
    int arr5[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    cout << "main: arr5: [\n";
    for (int iter1 = 0; iter1 < 3; iter1 += 1) {
        cout << "\t[";
        for (int iter2 = 0; iter2 < 3; iter2 += 1) {
            cout << arr5[iter1][iter2];
            if (iter2 < 2) {
                cout << ", ";
            }
        }
        if (iter1 < 2) {
            cout << "],\n";
        } else {
            cout << "]\n";
        }
    }
    cout << "]" << endl;

    // Initialize a pseudo-array
    int arr6[3 * 3] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9};
    cout << "main: arr6: [\n";
    for (int iter1 = 0; iter1 < 3; iter1 += 1) {
        cout << "\t[";
        for (int iter2 = 0; iter2 < 3; iter2 += 1) {
            cout << arr6[iter1 * 3 + iter2];
            if (iter2 < 2) {
                cout << ", ";
            }
        }
        if (iter1 < 2) {
            cout << "],\n";
        } else {
            cout << "]\n";
        }
    }
    cout << "]" << endl;

    // Use array as function argument
    int arr7[5] = {1, 2, 3};
    cout << "main: arr7: ";
    printArr(arr7, 5);
    cout << endl;
    editArr(arr7, 3, 4);
    cout << "main: called editArr" << endl;
    cout << "main: arr7: ";
    printArr(arr7, 5);
    cout << endl;

    // Use library arrays
    array<int, 5> arr8 = {1, 2, 3};
    cout << "main: arr8: [";
    for (int iter = 0; iter < 5; iter += 1) {
        cout << arr8[iter];
        if (iter < 4) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return EXIT_SUCCESS;
}

void printArr(int arr[], int len) {
    cout << "[";
    for (int iter = 0; iter < len; iter += 1) {
        cout << arr[iter];
        if (iter < len - 1) {
            cout << ", ";
        }
    }
    cout << "]";
    cout.flush();
}

void editArr(int arr[], int idx, int val) {
    arr[idx] = val;
}

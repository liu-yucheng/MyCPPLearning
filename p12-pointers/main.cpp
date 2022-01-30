/* Ref: http://www.cplusplus.com/doc/tutorial/pointers
 * A program that shows the usage of C++ pointers. */

/* Copyright 2022 Yucheng Liu. GNU GPL3 license.
 * GNU GPL3 license copy: https://www.gnu.org/licenses/gpl-3.0.txt */

#include <iostream>
#include <string>

using namespace std;

void *incptr(void *, size_t);
int addInt(int, int);
int subInt(int, int);
int mulInt(int, int);
int divInt(int, int);
int calcInt(int, int, int (*)(int, int));

int main(int argc, char **argv) {
    int v1 = 1;
    cout << "main: v1: " << v1 << endl;
    // Use ref operators to initialize pointers
    int *p1 = &v1;
    cout << "main: p1 (&v1): " << p1 << endl;
    // Use deref operators to initialize variables
    int v2 = *p1;
    cout << "main: v2 (*p1): " << v2 << endl;

    int a1[5] = {1, 2, 3, 4, 5};
    int *p2 = a1;
    // Use pointers as array iterators
    cout << "main: a1: [";
    while (p2 < a1 + 5) {
        cout << *p2;
        if (p2 < a1 + 4) {
            cout << ", ";
        }
        p2 += 1;
    }
    cout << "]" << endl;

    // Use pointer incrementations
    char a2[5] = {'1', '2', '3', '4', '5'};
    short a3[5] = {(short)1, (short)2, (short)3, (short)4, (short)5};
    long a4[5] = {1L, 2L, 3L, 4L, 5L};

    char *p3 = &a2[1];
    short *p4 = &a3[1];
    long *p5 = &a4[1];

    cout << "main:\n"
         << "\ta2[1]: @p3: " << (int *)p3 << " =: '" << *p3 << "'\n"
         << "\ta3[1]: @p4: " << p4 << " =: " << *p4 << "\n"
         << "\ta4[1]: @p5: " << p5 << " =: " << *p5 << endl;

    p3 += 1;
    p4 += 1;
    p5 += 1;

    cout << "main:\n"
         << "\ta2[2]: @p3: " << (int *)p3 << " =: '" << *p3 << "'\n"
         << "\ta3[2]: @p4: " << p4 << " =: " << *p4 << "\n"
         << "\ta4[2]: @p5: " << p5 << " =: " << *p5 << endl;

    // Explore pointer incrementation details
    int a5[2];
    a5[0] = 1;
    a5[1] = 2;
    int *p6 = a5;
    cout << "main:\n"
         << "\ta5: [" << a5[0] << ", " << a5[1] << "]\n"
         << "\tp6: " << p6 << " *: " << *p6 << endl;
    // Increment p6 and deref (p6 - 1)
    // Equivalent to (p6 += 1, *(p6 - 1))
    int v3 = *p6++;
    cout << "main: executed v3 = *p6++" << endl;
    cout << "main:\n"
         << "\ta5: [" << a5[0] << ", " << a5[1] << "]\n"
         << "\tv3: " << v3 << '\n'
         << "\tp6: " << p6 << " *: " << *p6 << endl;

    // Reinitialize a5 and p6
    a5[0] = 1;
    a5[1] = 2;
    p6 = a5;
    cout << "main:\n"
         << "\ta5: [" << a5[0] << ", " << a5[1] << "]\n"
         << "\tp6: " << p6 << " *: " << *p6 << endl;
    // Increment p6 and deref p6
    // Equivalent to (p6 += 1, *p6)
    int v4 = *++p6;
    cout << "main: executed v4 = *++p6" << endl;
    cout << "main:\n"
         << "\ta5: [" << a5[0] << ", " << a5[1] << "]\n"
         << "\tv4: " << v4 << '\n'
         << "\tp6: " << p6 << " *: " << *p6 << endl;

    a5[0] = 1;
    a5[1] = 2;
    p6 = a5;
    cout << "main:\n"
         << "\ta5: [" << a5[0] << ", " << a5[1] << "]\n"
         << "\tp6: " << p6 << " *: " << *p6 << endl;
    // Deref p6 and pre-increment the derefed value
    // Equivalent to (*p6 += 1)
    int v5 = ++*p6;
    cout << "main: executed v5 = ++*p6" << endl;
    cout << "main:\n"
         << "\ta5: [" << a5[0] << ", " << a5[1] << "]\n"
         << "\tv5: " << v5 << '\n'
         << "\tp6: " << p6 << " *: " << *p6 << endl;

    a5[0] = 1;
    a5[1] = 2;
    p6 = a5;
    cout << "main:\n"
         << "\ta5: [" << a5[0] << ", " << a5[1] << "]\n"
         << "\tp6: " << p6 << " *: " << *p6 << endl;
    // Deref p6 and post-increment the derefed value
    // Equivalent to (*p6 += 1, *p6 - 1)
    int v6 = (*p6)++;
    cout << "main: executed v6 = ++*p6" << endl;
    cout << "main:\n"
         << "\ta5: [" << a5[0] << ", " << a5[1] << "]\n"
         << "\tv6: " << v6 << '\n'
         << "\tp6: " << p6 << " *: " << *p6 << endl;

    // Declare costant pointers
    int const v7 = 1;
    int v8 = 1;
    // non-const pointer to const int value
    int const *p7 = &v7;
    // const pointer to non-const int value
    int *const p8 = &v8;
    // const pointer to const int value
    int const *const p9 = &v7;
    cout << "main: declared non-const and const pointers" << endl;

    // Use pointers to access string literals
    char const *p10 = "string literal";
    cout << "main: p10: @: " << (int *)p10 << " =: \"" << p10 << "\"" << endl;

    // Use pointers to pointers
    int v9 = 1;
    int *p11 = &v9;
    int **p12 = &p11;
    cout << "main:\n"
         << "\tv9: " << v9 << "\n"
         << "\tp11: " << p11 << " *p11: " << *p11 << "\n"
         << "\tp12: " << p12 << " *p12: " << *p12 << " **p12: " << **p12
         << endl;

    // Use void pointers
    char s1[7] = "string";
    void *p13 = (void *)s1;
    cout << "main: s1: ";
    while (p13 < s1 + 7) {
        cout << *((char *)p13);
        p13 = incptr(p13, 1);
    }
    cout << endl;

    // Declare null pointers
    int *p14 = 0;
    int *p15 = nullptr;
    int *p16 = NULL;
    cout << "main: declared null pointers" << endl;

    // Use function pointers
    int v10 = 4, v11 = 3;
    // Assign functions to function pointers
    int (*calc)(int, int, int (*)(int, int)) = calcInt;
    // Use functions that takes function pointer arguments
    cout << "main: calc(v10, v11, addInt): " << calc(v10, v11, addInt) << endl;
    cout << "main: calc(v10, v11, subInt): " << calc(v10, v11, subInt) << endl;
    cout << "main: calc(v10, v11, mulInt): " << calc(v10, v11, mulInt) << endl;
    cout << "main: calc(v10, v11, divInt): " << calc(v10, v11, divInt) << endl;

    return EXIT_SUCCESS;
}

void *incptr(void *ptr, size_t byByte) {
    char *casted = (char *)ptr;
    casted += byByte;
    ptr = (void *)casted;
    return casted;
}

int addInt(int v1, int v2) {
    return v1 + v2;
}

int subInt(int v1, int v2) {
    return v1 - v2;
}

int mulInt(int v1, int v2) {
    return v1 * v2;
}

int divInt(int v1, int v2) {
    return v1 / v2;
}

int calcInt(int v1, int v2, int (*op)(int, int)) {
    return op(v1, v2);
}

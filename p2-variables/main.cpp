/* Ref:
 * http://www.cplusplus.com/doc/tutorial/variables/
 * A program that shows the initialization and mutation of variables of
 * primitive types. */

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    // Declare variables
    int a, b, result;
    // Initialize variables
    a = 5;
    b = 2;
    // Increment variable a
    a += 1;
    // Calculate result
    result = a - b;
    cout << result << endl;
    
    return 0;
}

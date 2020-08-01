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
    // Calculate and print result
    result = a - b;
    cout << result << endl;
    // Declare some other variables
    int a2 = 5, b2 (3), c2 {2};
    // Mutate a2
    a2 = a2 + b2;
    // Calculate and print result
    result = a2 - c2;
    cout << result << endl;
    // Declare an auto variable
    auto a3 = a2;
    // Print the auto variable
    cout << a3 << endl;
    // Declare a decltype variable
    decltype(a3) a4 = a3;
    // Print the decltype variable
    cout << a4 << endl;
    // Declare a string variable
    string s = "Initial content";
    // Print the string variable
    cout << s << endl;
    // Mutate the string
    s = "Mutated content";
    cout << s << endl;
    
    return 0;
}

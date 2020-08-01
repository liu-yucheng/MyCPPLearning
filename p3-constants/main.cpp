/* Ref: http://www.cplusplus.com/doc/tutorial/constants/
 * A program that shows the usage of constants. */

#include <iostream>

using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

const double pi = 3.14159;
const char newline = '\n';

int main(int argc, char **argv) {
    double radius = 5.0, circ, circ2;
    // Use variables with const keyword
    circ = 2 * pi * radius;
    cout << circ;
    cout << newline;
    // Use macro constant definitions
    circ2 = 2 * PI * radius;
    cout << circ2;
    cout << NEWLINE;

    return 0;
}

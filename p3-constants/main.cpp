/* Ref: http://www.cplusplus.com/doc/tutorial/constants/
 * A program that shows the usage of constants. */

/* Copyright 2022 Yucheng Liu. GNU GPL3 license.
 * GNU GPL3 license copy: https://www.gnu.org/licenses/gpl-3.0.txt */

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

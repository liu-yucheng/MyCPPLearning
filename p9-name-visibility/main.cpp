/* Ref: http://www.cplusplus.com/doc/tutorial/namespaces/
 * A program that shows the usage of C++ name visibility. */

/* Copyright 2022 Yucheng Liu. GNU GPL3 license.
 * GNU GPL3 license copy: https://www.gnu.org/licenses/gpl-3.0.txt */

#include <iostream>
#include <string>

// Use the std namespace
using namespace std;

// Global Variables
string g1 = "global variable 1";
// Define an uninitialized variable
int g2; // automatically set to 0 upon init

// Global Functions
void gFunc1();
void gFunc2();

// Global namespaces
namespace space1 {
string v1 = "space1 variable 1";
string v2 = "space1 variable 2";
}  // namespace space1

namespace space2 {
string v1 = "space2 variable 1";
string v2 = "space2 variable 2";
}  // namespace space2

int main(int argc, char **argv) {
    // Print variable states
    cout << "main: g1: \"" << g1 << "\"\n"
         << endl;

    gFunc1();

    cout << "main: called gFunc1"
         << endl;
    cout << "main: g1: \"" << g1 << "\"\n"
         << endl;

    gFunc2();

    cout << "main: called gFunc2"
         << endl;
    cout << "main: g1: \"" << g1 << "\"\n"
         << endl;

    string l1 = "outer local variable 1",
           l2 = "outer local variable 2";

    cout << "main outer:\n"
         << "\tl1: \"" << l1 << "\"\n"
         << "\tl2: \"" << l2 << "\"\n"
         << endl;

    {
        string l1 = "inner local variable 1";
        l2 = "outer local variable 2 updated by inner";

        cout << "main inner:\n"
             << "\tl1: \"" << l1 << "\"\n"
             << "\tl2: \"" << l2 << "\"\n"
             << endl;
    }

    cout << "main outer:\n"
         << "\tl1: \"" << l1 << "\"\n"
         << "\tl2: \"" << l2 << "\"\n"
         << endl;

    // Use space1 namespace
    using namespace space1;

    // Aliase namespace
    namespace space3 = space1;

    cout << "main using space1:\n"
         << "\tv1: \"" << v1 << "\"\n"
         << "\tv2: \"" << v2 << "\"\n"
         << "\tspace1::v1: \"" << space1::v1 << "\"\n"
         << "\tspace1::v2: \"" << space1::v2 << "\"\n"
         << "\tspace2::v1: \"" << space2::v1 << "\"\n"
         << "\tspace2::v2: \"" << space2::v2 << "\"\n"
         << "\tspace3::v1: \"" << space3::v1 << "\"\n"
         << "\tspace3::v2: \"" << space3::v2 << "\"\n"
         << endl;
    
    // Define an uninitialized variable
    int l3; // may contain any garbage value

    cout << "main:\n"
        << "\tuninit l3: " << l3 << "\n"
        << "\tuninit g2: " << g2
        << endl;

    return EXIT_SUCCESS;
}

void gFunc1() {
    // Local variables
    string l1 = "gFunc1 local variable 1";

    // Update global variable g1
    g1 = "global variable 1 updated by gFunc1";

    // Print variable states
    cout << "gFunc1:\n"
         << "\tl1: \"" << l1 << "\"\n"
         << "\tg1: \"" << g1 << "\"\n"
         << endl;
}

void gFunc2() {
    string l1 = "gFunc2 local variable 1";

    // Print variable states
    cout << "gFunc2:\n"
         << "\tl1: \"" << l1 << "\"\n"
         << "\tg1: \"" << g1 << "\"\n"
         << endl;
}

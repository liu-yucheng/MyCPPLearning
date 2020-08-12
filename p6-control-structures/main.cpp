/* Ref: http://www.cplusplus.com/doc/tutorial/control/
 * A program that shows the usage of C++ flow control. */

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    cout << "<Options>\n"
         << "0: Exit\n"
         << "1/2: If/else statement\n"
         << "3/4: While loop once/twice\n"
         << "5/6: Do-while loop once/twice\n"
         << "7/8: For loop once/twice\n"
         << "9: Range-based for loop\n";
    cout << endl;

// Show the usage of goto statement
loopStart:

    int inInt = 0;
    cout << "Enter an integer: ";
    cin >> inInt;
    cout << "The integer is: " << inInt;
    cout << endl;

    // Show the usage of switch statement
    switch (inInt) {
        case 0:
            break;
        case 1:
        case 2:
            // Show the usage of if/else
            if (inInt == 1) {
                cout << "In if";
            } else {
                cout << "In else";
            }
            cout << endl;
            break;
        case 3:
        case 4: {
            // Show the usage of while
            int iter = 0,
                bound = inInt - 2;
            while (iter < bound) {
                cout << "In while; iter:" << iter << "\n";
                iter += 1;
            }
            cout.flush();
        } break;
        case 5:
        case 6: {
            // Show the usage of do-while
            int iter = 0,
                bound = inInt - 4;
            do {
                cout << "In do-while; iter:" << iter << "\n";
                iter += 1;
            } while (iter < bound);
            cout.flush();
        } break;
        case 7:
        case 8:
            // Show the usage of for
            for (int iter = 0; iter < inInt - 6; iter += 1) {
                cout << "In for; iter:" << iter << "\n";
            }
            cout.flush();
            break;
        case 9: {
            // Show the usage of range-based for
            string msgs[] = {"0-range-based", "1-for"};
            for (string msg : msgs) {
                cout << "In range-based for; msg: " << msg << "\n";
            }
            cout.flush();
        } break;
        default:
            cout << "Undefined option; Enter again";
            cout << endl;
            break;
    }

    // Show the usage of goto statement
    // Loop back when the integer is not 0
    if (inInt != 0) {
        cout << endl;
        goto loopStart;
    }

    cout << "Program exits\n" << endl;
    return 0;
}

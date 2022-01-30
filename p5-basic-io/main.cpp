/* Ref: http://www.cplusplus.com/doc/tutorial/basic_io/
 * A program that shows the usage of C++ basic io. */

/* Copyright 2022 Yucheng Liu. GNU GPL3 license.
 * GNU GPL3 license copy: https://www.gnu.org/licenses/gpl-3.0.txt */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
    // Take an integer from keyboard input
    int curIn;
    cout << "Enter an integer: ";
    cin >> curIn;
    // Ignore the buffered new line character
    cin.ignore();
    cout << "The integer is: " << curIn << '\n' << endl;

    // Take a word from keyboard input
    string curIn2;
    cout << "Enter a word: ";
    cin >> curIn2;
    cin.ignore();
    cout << "The word is: " << curIn2 << '\n' << endl;

    // Take 2 integers from keyboard input
    int curIn3, curIn4;
    cout << "Enter 2 integers:\n";
    cin >> curIn3 >> curIn4;
    cin.ignore();
    cout << "The 1st integer is: " << curIn3 << '\n';
    cout << "The 2nd integer is: " << curIn4 << '\n' << endl;

    // Take a line from keyboard input
    string curIn5;
    cout << "Enter a line:\n";
    getline(cin, curIn5);
    cout << "The line is:\n";
    cout << curIn5 << '\n' << endl;

    // Parse an integer from a string
    string numStr = "1234";
    int num;
    cout << "Parsing integer from string...\n";
    stringstream(numStr) >> num;
    cout << "The parsed integer is: " << num << endl;

    return 0;
}

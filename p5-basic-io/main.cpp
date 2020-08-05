/* Ref: http://www.cplusplus.com/doc/tutorial/basic_io/
 * A program that shows the usage of C++ basic io. */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
    int curIn;
    cout << "Enter an integer: ";
    cin >> curIn;
    cin.ignore();
    cout << "The integer is: " << curIn << '\n' << endl;

    string curIn2;
    cout << "Enter a word: ";
    cin >> curIn2;
    cin.ignore();
    cout << "The word is: " << curIn2 << '\n' << endl;

    int curIn3, curIn4;
    cout << "Enter 2 integers:\n";
    cin >> curIn3 >> curIn4;
    cin.ignore();
    cout << "The 1st integer is: " << curIn3 << '\n';
    cout << "The 2nd integer is: " << curIn4 << '\n' << endl;

    string curIn5;
    cout << "Enter a line:\n";
    getline(cin, curIn5);
    cout << "The line is:\n";
    cout << curIn5 << '\n' << endl;

    string numStr = "1234";
    int num;
    cout << "Parsing integer from string...\n";
    stringstream(numStr) >> num;
    cout << "The parsed integer is: " << num << endl;

    return 0;
}

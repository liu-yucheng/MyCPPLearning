/* Ref: http://www.cplusplus.com/doc/tutorial/ntcs/
 * A program that shows the usage of C++ character sequences. */

/* Copyright 2022 Yucheng Liu. GNU GPL3 license.
 * GNU GPL3 license copy: https://www.gnu.org/licenses/gpl-3.0.txt */

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    // Use character arrays
    char str1[5] = "str1";
    cout << "main: str1: \"" << str1 << "\"" << endl;

    char str2[5] = {'s', 't', 'r', '2', '\0'};
    cout << "main: str2: \"" << str2 << "\"" << endl;

    char str3[5];
    str3[0] = 's';
    str3[1] = 't';
    str3[2] = 'r';
    str3[3] = '3';
    str3[4] = '\0';
    cout << "main: str3: \"" << str3 << "\"" << endl;

    // Use library strings
    string str4 = "str4";
    cout << "main: str4: \"" << str4 << "\"" << endl;

    string str5 = "str5";
    const char *str5_cstr = str5.c_str();
    cout << "main: str5: \"" << str5 << "\"" << endl;

    return EXIT_SUCCESS;
}

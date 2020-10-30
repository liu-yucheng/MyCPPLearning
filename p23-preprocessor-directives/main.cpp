/* Ref: http://www.cplusplus.com/doc/tutorial/preprocessor/
 * A program that shows the usage of C++ preprocessor directives.
 * NOTE: This does not cover the usage of #pragma statements */

// Use #include statements
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
// Use #define statements
#define MACRO_MSG "message"
    cout << "main: MACRO_MSG: " << MACRO_MSG << endl;

// Use #ifndef statements
#ifndef MACRO_MSG
#define MACRO_MSG "message 2"
#endif
    cout << "main: MACRO_MSG: " << MACRO_MSG << endl;

// Use #ifdef statements
#ifdef MACRO_MSG
#undef MACRO_MSG
#define MACRO_MSG "message 3"
#endif
    cout << "main: MACRO_MSG: " << MACRO_MSG << endl;

// Use the # operator (string literal operator)
#define STR(target) #target
    cout << "main: STR(message): " << STR(message) << endl;

// Use the ## operator (concat operator)
#define CONCAT(target1, target2) target1##target2
    string concatMsg = "message";
    cout << "main: CONCAT(concat, Msg): " << CONCAT(concat, Msg) << endl;

#define OPTION 0
// Use #if-#elif-#else statements
#if OPTION == 0
    cout << "main: OPTION is 0" << endl;
#define MODE 0
#elif OPTION == 1
    cout << "main: OPTION is 1" << endl;
#define MODE 1
#else
    cout << "main: OPTION is neither 0 nor 1" << endl;
#define MODE -1
#endif
    cout << "main: MODE: " << MODE << endl;

// Use #line statements (line control statements)
#line 1024 "main.2020.c"
    cout << "main: compiler sees file name: " << __FILE__ << endl;
    cout << "main: compiler sees line number: " << __LINE__ << endl;

    // Use #error statements
    // NOTE: UNCOMMENT to take effect
    // #error error message

    // Use predefined __DATE__ and __TIME__ macros
    cout << "main: compilation starts on: " << __DATE__ << endl;
    cout << "main: compilation starts at: " << __TIME__ << endl;

    // Use the __cplusplus macro
    cout << "main: __cplusplus: " << __cplusplus << endl;

    return EXIT_SUCCESS;
}

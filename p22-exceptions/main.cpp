/* Ref: http://www.cplusplus.com/doc/tutorial/exceptions/
 * A program that shows the usage of C++ exception handling. */

/* Copyright 2022 Yucheng Liu. GNU GPL3 license.
 * GNU GPL3 license copy: https://www.gnu.org/licenses/gpl-3.0.txt */

#include <iostream>
#include <string>

using namespace std;

void throwInt() {
    // Use throw statements
    throw 42;
}

void throwStr() {
    throw "message"s;
}

void throwFloat() {
    throw 3.14f;
}

void throwNothing() {
    throw;
}

// Define standard exceptions
class SampleExc : public exception {
   private:
    string msgState;

   public:
    SampleExc(string msg) {
        msgState = msg;
    }

    virtual const char *what() const throw() {
        return msgState.c_str();
    }
};

void throwSampleExc() {
    throw SampleExc("message");
}

int main(int argc, char **argv) {
    // Use try-catch blocks
    try {
        cout << "main: try: executing" << endl;
        throwInt();
    } catch (int errNum) {
        cout << "main: catch: error number: " << errNum << endl;
    }

    // Use multiple handler try-catch blocks
    try {
        cout << "main: try: executing" << endl;
        throwStr();
    } catch (int errNum) {
        cout << "main: catch: error number: " << errNum << endl;
    } catch (string errMsg) {
        cout << "main: catch: error message: " << errMsg << endl;
    }

    // Use nested try-catch blocks
    try {
        cout << "main: try: executing" << endl;
        try {
            cout << "main: try: try: executing" << endl;
            throwFloat();
        } catch (float errData) {
            cout << "main: try: catch: error data: " << errData << endl;
            throwNothing();
        }
    } catch (...) {
        cout << "main: catch: error occured" << endl;
    }

    // Use try-catch to handle standard exceptions
    try {
        cout << "main: try: executing" << endl;
        throwSampleExc();
    } catch (exception &exc) {
        cout << "main: catch: exception message: " << exc.what() << endl;
    }

    return EXIT_SUCCESS;
}

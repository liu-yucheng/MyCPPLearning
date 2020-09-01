/* Ref: http://www.cplusplus.com/doc/tutorial/functions/
 * A program that shows the usage of C++ functions. */

#include <iostream>
#include <string>

using namespace std;

// Use function declarations
int add(int a, int b);
void say(string s);
void inc(int& a);
string concat(const string& a, const string& b);
inline string concatInline(string& a, string& b);
void incBy(int& a, int b = 1);
void recLoop(int& iter);

int main(int argc, char** argv) {
    // Use function with int return type
    int a = 1, b = 2, c;
    c = add(a, b);
    cout << "add: " << a << '+' << b << '=' << c;
    cout << endl;

    // Use function with void (no) return type
    say("hello");

    // Use function with reference argument
    int a2 = 1;
    cout << "before inc:\ta2:" << a2;
    cout << endl;
    inc(a2);
    cout << "after inc:\ta2:" << a2;
    cout << endl;

    // Use function with constant reference argument
    string hello = "Hello", world = "World";
    string helloWorld = concat(hello, world);
    cout << "concat: "
         << '\"' << hello << '\"'
         << " + "
         << '\"' << world << '\"'
         << " = "
         << "\"" << helloWorld << '\"';
    cout << endl;

    // Use inline function
    string hello2 = "Hello", world2 = "World";
    string helloWorld2 = concatInline(hello2, world2);
    cout << "concatInline: "
         << '\"' << hello2 << '\"'
         << " + "
         << '\"' << world2 << '\"'
         << " = "
         << "\"" << helloWorld2 << '\"';
    cout << endl;

    // Use function with optional argument
    int a3 = 1;
    cout << "before incBy 1:\ta3:" << a3;
    cout << endl;
    incBy(a3);
    cout << "after incBy 1:\ta3:" << a3;
    cout << endl;
    int a4 = 1;
    cout << "before incBy 2:\ta4:" << a4;
    cout << endl;
    incBy(a4, 2);
    cout << "after incBy 2:\ta4:" << a4;
    cout << endl;

    // Use recursive function
    int iter = 3;
    recLoop(iter);

    // Use exit status
    return EXIT_SUCCESS;
}

// Use function implementations
int add(int a, int b) {
    return a + b;
}

void say(string s) {
    cout << "say: " << s;
    cout << endl;
}

void inc(int& a) {
    a += 1;
}

string concat(const string& a, const string& b) {
    return a + b;
}

inline string concatInline(string& a, string& b) {
    return a + b;
}

void incBy(int& a, int b) {
    a += b;
}

void recLoop(int& iter) {
    cout << "recLoop: iter:" << iter;
    cout << endl;
    if (iter <= 1) {
        cout << "recLoop: done";
        cout << endl;
        return;
    } else {
        iter -= 1;
        recLoop(iter);
    }
}

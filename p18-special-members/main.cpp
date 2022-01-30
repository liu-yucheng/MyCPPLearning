/* Ref: http://www.cplusplus.com/doc/tutorial/classes2/
 * A program that shows the usage of special members of C++ classes. */

/* Copyright 2022 Yucheng Liu. GNU GPL3 license.
 * GNU GPL3 license copy: https://www.gnu.org/licenses/gpl-3.0.txt */

#include <iostream>
#include <string>

using namespace std;

// Define classes
class Spec {
   private:
    static int countState;
    int copySNState;

   public:
    // Define the default constructor
    Spec();
    // Define the copy constructor
    Spec(const Spec&);
    // Define the move constructor
    Spec(Spec&&);
    // Define custom constructors
    Spec(int);
    // Define the destructor
    ~Spec();

    // Define the copy assignment operator
    Spec& operator=(const Spec&);
    // Define the move assignment operator
    Spec& operator=(Spec&&);

    // Define other methods
    static int count();
    int copySN();
    string strRepr();
};

// Initialize fields
int Spec::countState = 0;

// Implement the constructors
Spec::Spec() {
    countState += 1;
    copySNState = 0;
    cout << "Spec:\n"
         << "\tdefault constructor called\n"
         << "\tcount: " << countState << endl;
}

Spec::Spec(const Spec& other) {
    countState += 1;
    copySNState = other.copySNState + 1;
    cout << "Spec:\n"
         << "\tcopy constructor called\n"
         << "\tcount: " << countState << "\n"
         << "\tthis->copySN: " << copySNState << endl;
}

Spec::Spec(Spec&& original) {
    countState += 1;
    copySNState = original.copySNState;
    cout << "Spec:\n"
         << "\tmove constructor called\n"
         << "\tcount: " << countState << endl;
}

Spec::Spec(int customCopySN) {
    countState += 1;
    copySNState = customCopySN;
    cout << "Spec:\n"
         << "\tcustom constructor called\n"
         << "\tcount: " << countState << endl;
}

// Implement the destructor
Spec::~Spec() {
    countState -= 1;
    cout << "Spec:\n"
         << "\tdestructor called\n"
         << "\tcount: " << countState << endl;
}

// Implement operators
Spec& Spec::operator=(const Spec& other) {
    copySNState = other.copySNState;
    cout << "Spec:\n"
         << "\tcopy assignment operator called\n"
         << "\tthis->copySN: " << copySNState << endl;
    return *this;
}

Spec& Spec::operator=(Spec&& original) {
    copySNState = original.copySNState;
    cout << "Spec:\n"
         << "\tmove assignment operator called\n"
         << "\tthis->copySN: " << copySNState << endl;
    return *this;
}

// Implement other methods
int Spec::count() {
    return countState;
}

int Spec::copySN() {
    return copySNState;
}

string Spec::strRepr() {
    string result = "{ ";
    {
        result += "copySN: " + to_string(copySNState);
    }
    result += " }";
    return result;
}

Spec makeSpec42() {
    return Spec(42);
}

int main(int argc, char** argv) {
    // Use default constructors
    cout << "main: start using default constructors" << endl;
    Spec var1;
    Spec* ptr1 = new Spec;

    // Use copy constructors
    cout << "main: start using copy constructors" << endl;
    Spec* ptr2 = new Spec(*ptr1);
    Spec* ptr3 = new Spec(*ptr2);

    // Use copy assignment operators
    cout << "main: start using copy assignment operators" << endl;
    cout << "main: ptr2: *Spec" << ptr2->strRepr() << endl;
    *ptr2 = *ptr3;
    cout << "main: ptr2: *Spec" << ptr2->strRepr() << endl;

    // Use move constructors
    cout << "main: start using move constructors" << endl;
    Spec var2 = move(makeSpec42());

    // Use move assignment operators
    cout << "main: start using move assignment operators" << endl;
    Spec* ptr4 = new Spec;
    *ptr4 = Spec(*ptr2);

    // (Implicitly) use destructors
    cout << "main: start using destructors" << endl;
    delete ptr1;
    delete ptr2;
    delete ptr3;
    delete ptr4;
    // (Automatically) delete stack-allocated (static) memory objects
    // auto-delete &var1, &var2
    return EXIT_SUCCESS;
}

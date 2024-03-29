/* Ref: http://www.cplusplus.com/doc/tutorial/templates/
 * A program that shows the usage of C++ classes.
 * This is part 2 of 2.
 * 
 * <<<< NOTE >>>>
 * This program covers NOT the usage of "const" keyword inside classes.
 * This program has about 300 lines, which is longer than expected. */

/* Copyright 2022 Yucheng Liu. GNU GPL3 license.
 * GNU GPL3 license copy: https://www.gnu.org/licenses/gpl-3.0.txt */

#include <iostream>
#include <string>

using namespace std;

// Declare classes
class Vector2D {
   private:
    static int countState;
    float xState, yState;

   public:
    // Declare normal constructors
    Vector2D();
    Vector2D(float, float);

    // Declare copy constructors
    Vector2D(Vector2D *);

    // Declare field access methods
    int count();

    float x();
    float x(float);

    float y();
    float y(float);

    // Declare operator methods
    Vector2D operator+(Vector2D);
    Vector2D operator-(Vector2D);
    Vector2D *operator=(Vector2D);
    bool operator==(Vector2D);

    // Declare other methods
    string strRepr();
};

// Implement normal constructors
Vector2D::Vector2D() {
    xState = 0.0f;
    yState = 0.0f;
    countState += 1;
}

Vector2D::Vector2D(float x, float y) {
    xState = x;
    yState = y;
    countState += 1;
}

// Implement copy constructors
Vector2D::Vector2D(Vector2D *vectorPtr) {
    xState = vectorPtr->xState;
    yState = vectorPtr->yState;
    countState += 1;
}

int Vector2D::countState = 0;

// Implement field access methods
float Vector2D::x() {
    return xState;
}

float Vector2D::x(float newX) {
    float oldX = xState;
    xState = newX;
    return oldX;
}

float Vector2D::y() {
    return yState;
}

float Vector2D::y(float newY) {
    float oldY = yState;
    yState = newY;
    return oldY;
}

int Vector2D::count() {
    return countState;
}

// Implement operator methods
Vector2D Vector2D::operator+(Vector2D other) {
    Vector2D result;
    result.xState = xState + other.xState;
    result.yState = yState + other.yState;
    return result;
}

Vector2D Vector2D::operator-(Vector2D other) {
    Vector2D result;
    result.xState = xState - other.xState;
    result.yState = yState - other.yState;
    return result;
}

Vector2D *Vector2D::operator=(Vector2D other) {
    // Use "this" keyword
    this->xState = other.xState;
    this->yState = other.yState;
    return this;
}

bool Vector2D::operator==(Vector2D other) {
    float threshold = 1e-7f;
    bool result = true;
    float diffX = xState - other.xState;
    result &= diffX <= threshold && diffX >= -threshold;
    float diffY = yState - other.yState;
    result &= diffY <= threshold && diffY >= -threshold;
    return result;
}

// Implement other methods
string Vector2D::strRepr() {
    string result = "{\n";
    {
        result += "\tstatic count: " + to_string(countState) + "\n";
        result += "\tx: " + to_string(xState) + "\n";
        result += "\ty: " + to_string(yState) + "\n";
    }
    result += "}";
    return result;
}

// Declare class templates
template <class T>
class Wrap {
   private:
    // Declare internal states
    T valState;

   public:
    // Declare constructors
    Wrap(T);

    // Declare field access methods
    T val();
    T val(T);

    // Declare other methods
    string strRepr();
};

// Implement class template methods
template <class T>
Wrap<T>::Wrap(T val) {
    valState = val;
}

template <class T>
T Wrap<T>::val() {
    return valState;
}

template <class T>
T Wrap<T>::val(T newVal) {
    T oldVal = valState;
    valState = newVal;
    return oldVal;
}

template <class T>
string Wrap<T>::strRepr() {
    string result = "{ val:" + to_string(valState) + " }";
    return result;
}

// Declare specialized class templates
template <>
class Wrap<char> {
   private:
    char valState;

   public:
    Wrap(char);

    char val();
    char val(char);

    char makeLower();
    char makeUpper();

    string strRepr();
};

Wrap<char>::Wrap(char val) {
    valState = val;
}

char Wrap<char>::val() {
    return valState;
}

char Wrap<char>::val(char newVal) {
    char oldVal = valState;
    valState = newVal;
    return valState;
}

char Wrap<char>::makeLower() {
    if (valState >= 'A' && valState <= 'Z') {
        char caseDiff = 'a' - 'A';
        char oldVal = valState;
        valState += caseDiff;
        return oldVal;
    } else {
        return valState;
    }
}

char Wrap<char>::makeUpper() {
    if (valState >= 'a' && valState <= 'z') {
        char caseDiff = 'A' - 'a';
        char oldVal = valState;
        valState += caseDiff;
        return oldVal;
    } else {
        return valState;
    }
}

string Wrap<char>::strRepr() {
    string result = "{ val: ";
    result += valState;
    result += " }";
    return result;
}

// <<<< Main method >>>>
int main(int argc, char **argv) {
    Vector2D *ptr1, *ptr2, *ptr3, *ptr4, *ptr5;

    ptr1 = new Vector2D();
    cout << "main: ptr1: *Vector2D " << ptr1->strRepr() << endl;
    ptr2 = new Vector2D(1.0f, 2.0f);
    cout << "main: ptr2: *Vector2D " << ptr2->strRepr() << endl;

    cout << "main: *ptr1 == *ptr2: " << (*ptr1 == ptr2) << endl;

    *ptr1 = *ptr2;
    cout << "main: executed \"*ptr1 = *ptr2\"" << endl;
    cout << "main: *ptr1 == *ptr2: " << (*ptr1 == *ptr2) << endl;
    cout << "main: ptr1: *Vector2D " << ptr1->strRepr() << endl;
    cout << "main: ptr2: *Vector2D " << ptr2->strRepr() << endl;

    Vector2D var1 = *ptr1 + *ptr2;
    ptr3 = &var1;
    cout << "main: ptr3: *Vector2D " << ptr3->strRepr() << endl;

    Vector2D var2 = *ptr1 - *ptr2;
    ptr4 = &var2;
    cout << "main: ptr4: *Vector2D " << ptr4->strRepr() << endl;

    ptr5 = new Vector2D(ptr3);
    cout << "main: ptr5: *Vector2D " << ptr5->strRepr() << endl;

    delete ptr1;
    delete ptr2;
    delete ptr5;

    Wrap<int> *ptr6 = new Wrap<int>(0);
    cout << "main: ptr6: *Wrap<int> " << ptr6->strRepr() << endl;

    int var3 = ptr6->val();
    var3 += 1;
    ptr6->val(var3);
    cout << "main: ptr6: *Wrap<int> " << ptr6->strRepr() << endl;

    Wrap<char> *ptr7 = new Wrap<char>('y');
    cout << "main: ptr7: *Wrap<char> " << ptr7->strRepr() << endl;

    ptr7->makeUpper();
    cout << "main: ptr7: *Wrap<char> " << ptr7->strRepr() << endl;

    ptr7->val('X');
    cout << "main: ptr7: *Wrap<char> " << ptr7->strRepr() << endl;

    ptr7->makeLower();
    cout << "main: ptr7: *Wrap<char> " << ptr7->strRepr() << endl;

    delete ptr6;
    delete ptr7;

    return EXIT_SUCCESS;
}

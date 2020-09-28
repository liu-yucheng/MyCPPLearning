/* Ref: http://www.cplusplus.com/doc/tutorial/templates/
 * A program that shows the usage of C++ classes. This is part 2 of 2. 
 * NOTE: This program does not show the use of const inside classes. */

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

    return EXIT_SUCCESS;
}

/* Ref: http://www.cplusplus.com/doc/tutorial/classes/
 * A program that shows the usage of C++ classes. This is part 1 of 2. */

/* Copyright 2022 Yucheng Liu. GNU GPL3 license.
 * GNU GPL3 license copy: https://www.gnu.org/licenses/gpl-3.0.txt */

#include <iostream>
#include <string>

using namespace std;

// Declare classes
class Rect {
   private:
    int widthState, heightState, areaState, circState;
    int centerXState, centerYState;

   public:
    // Declare constructors
    Rect(int width, int height);
    Rect(int width, int height, int centerX, int centerY);

    // Declare field access methods
    int width();
    int height();
    int centerX();
    int centerX(int newCenterX);
    int centerY();
    int centerY(int newCenterY);
    int area();
    int circ();

    // Declare other methods
    bool move(int newCenterX, int newCenterY);
    string strRepr();
};

// Implement constructors
Rect::Rect(int width, int height) {
    this->widthState = width;
    this->heightState = height;
    this->centerXState = 0;
    this->centerYState = 0;
    this->areaState = width * height;
    this->circState = 2 * (width + height);
}

Rect::Rect(int width, int height, int centerX, int centerY) {
    this->widthState = width;
    this->heightState = height;
    this->centerXState = centerX;
    this->centerYState = centerY;
    this->areaState = width * height;
    this->circState = 2 * (width + height);
}

// Implement field access methods
int Rect::width() {
    return this->widthState;
}

int Rect::height() {
    return this->heightState;
}

int Rect::centerX() {
    return this->centerXState;
}

int Rect::centerX(int newCenterX) {
    int oldCenterX = this->centerXState;
    this->centerXState = newCenterX;
    return oldCenterX;
}

int Rect::centerY() {
    return this->centerYState;
}

int Rect::centerY(int newCenterY) {
    int oldCenterY = this->centerYState;
    this->centerYState = newCenterY;
    return oldCenterY;
}

int Rect::area() {
    return this->areaState;
}

int Rect::circ() {
    return this->circState;
}

// Implement other methods
bool Rect::move(int newCenterX, int newCenterY) {
    bool moved = true;
    moved &= this->centerX(newCenterX) != newCenterX;
    moved &= this->centerY(newCenterY) != newCenterY;
    return moved;
}

string Rect::strRepr() {
    string repr = "{\n";
    {
        repr += "\twidth: " + to_string(widthState) + ", \n";
        repr += "\theight: " + to_string(heightState) + ", \n";
        repr += "\tcenterX: " + to_string(centerXState) + ", \n";
        repr += "\tcenterY: " + to_string(centerYState) + ", \n";
        repr += "\tarea: " + to_string(areaState) + ", \n";
        repr += "\tcirc: " + to_string(circState) + ", \n";
    }
    repr += "}";
    return repr;
}

// [[ NOTE ]]
// Struct and union are also considered as types of classes.

// <<<< Main method >>>>
int main(int argc, char **argv) {
    // Declare statically allocated objects
    Rect rect1(1, 2);
    cout << "main: rect1: Rect" << rect1.strRepr() << endl;

    // Declare dynamically allocated objects
    Rect *rect2Ptr = new Rect(3, 4, 5, 6);
    cout << "main: rect2Ptr: Rect *" << rect2Ptr->strRepr() << endl;
    delete rect2Ptr;

    // Declare arrays of objects
    Rect *rectArr1Ptr = new Rect[2]{
        {7, 8},
        {9, 10, 11, 12}};
    for (int iter = 0; iter < 2; iter += 1) {
        cout << "main: rectArr1Ptr[" << iter << "]: "
             << rectArr1Ptr[iter].strRepr() << endl;
    }
    delete[] rectArr1Ptr;

    return EXIT_SUCCESS;
}

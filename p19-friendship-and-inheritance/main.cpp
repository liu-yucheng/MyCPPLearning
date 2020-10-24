/* Ref: http://www.cplusplus.com/doc/tutorial/inheritance/
 * A program that shows the usage of C++ friendship and inheritance. */

#include <math.h>

#include <iostream>
#include <string>

using namespace std;

// Declare class names
class Rect;
class ParalGram;
class Square;
class Printable;

// Define classes
class Rect {
   protected:
    float widthState;
    float heightState;

   public:
    Rect(float, float);
    float width();
    float height();
    string strRepr();

    // Use friend functions
    friend void rotate90(Rect &);

    // Use friend class relationships
    static Rect from(const ParalGram &);
};

// Implement Rect methods
Rect::Rect(float width, float height) {
    widthState = width;
    heightState = height;
}

float Rect::width() {
    return widthState;
}

float Rect::height() {
    return heightState;
}

string Rect::strRepr() {
    string repr = "{ ";
    repr += "width: " + to_string(widthState) + " ";
    repr += "height: " + to_string(heightState) + " ";
    repr += "}";
    return repr;
}

// Implement Rect friend functions
void rotate90(Rect &target) {
    // Friend functions are not members but they can access private members
    float temp = target.widthState;
    target.widthState = target.heightState;
    target.heightState = temp;
}

class ParalGram {
    friend class Rect;

   private:
    float widthState;
    float heightState;
    float angle1DegState;
    float angle2DegState;

   public:
    ParalGram(float, float, float);
    float width();
    float height();
    float angle1Deg();
    float angle2Deg();
    string strRepr();
};

ParalGram::ParalGram(float width, float height, float angle1Deg) {
    widthState = width;
    heightState = height;
    angle1DegState = fmodf32(angle1Deg, 180);
    angle1DegState = abs(angle1DegState);
    angle2DegState = 180 - angle1DegState;
}

float ParalGram::width() {
    return widthState;
}

float ParalGram::height() {
    return heightState;
}

float ParalGram::angle1Deg() {
    return angle1DegState;
}

float ParalGram::angle2Deg() {
    return angle2DegState;
}

string ParalGram::strRepr() {
    string repr = "{\n";
    {
        repr += "\twidth: " + to_string(widthState) + "\n";
        repr += "\theight: " + to_string(heightState) + "\n";
        repr += "\tangle1Deg: " + to_string(angle1DegState) + "\n";
        repr += "\tangle2Deg: " + to_string(angle2DegState) + "\n";
    }
    repr += "}";
    return repr;
}

// Implement Rect-ParalGram friend class functions
Rect Rect::from(const ParalGram &target) {
    Rect result(target.widthState, target.heightState);
    return result;
}

// Use inheritance
// The protected inheritance keyword means that all the inherited fields with
// access keywords above ("more public") than protected become protected in the
// child classes
class Square : protected Rect {
   protected:
    float sizeState;

   public:
    Square(float);
    float size();
    string strRepr();
};

// The constructor call after the semicolon specifies the parent constructors
// to be invoked to initialize the child objects
Square::Square(float size) : Rect(size, size) {
    sizeState = size;
}

float Square::size() {
    return sizeState;
}

string Square::strRepr() {
    string repr = "{\n";
    {
        repr += "\tsize: " + to_string(sizeState) + "\n";
        repr += "\t(inherited) width: " + to_string(widthState) + "\n";
        repr += "\t(inherited) height: " + to_string(heightState) + "\n";
    }
    repr += "}";
    return repr;
}

class Printable {
   protected:
    void print();
};

void Printable::print() {
    cout << "{ (Printable) }";
    cout.flush();
}

// Use multiple inheritance
class PrintableSquare : public Square, public Printable {
   public:
    PrintableSquare(float);
    string strRepr();
    void print();
};

PrintableSquare::PrintableSquare(float size) : Square(size) {
}

string PrintableSquare::strRepr() {
    string repr = "{ ";
    repr += "(inherited) size: " + to_string(sizeState) + " ";
    repr += "}";
    return repr;
}

void PrintableSquare::print() {
    // Call overridden methods by specifying the parent class name
    this->Printable::print();
    cout << "{ (PrintableSquare)\n"
         << "\t(inherited) size: " << to_string(sizeState) << "\n"
         << "}";
    cout.flush();
}

// <<<< main function >>>>
int main(int argc, char **argv) {
    Rect var1(2, 3);
    cout << "main: var1: Rect" << var1.strRepr() << endl;

    // Use friend functions
    rotate90(var1);
    cout << "main: invoked rotate90(var1)" << endl;
    cout << "main: var1: Rect" << var1.strRepr() << endl;

    ParalGram var2(3, 4, 60);
    cout << "main: var2: ParalGram" << var2.strRepr() << endl;

    // Use friend classes
    Rect var3 = Rect::from(var2);
    cout << "main: var3: Rect" << var3.strRepr() << endl;

    // Use inheritance
    Square var4(5);
    cout << "main: var4: Square" << var4.strRepr() << endl;

    // Use multiple inheritance
    PrintableSquare var5(6);
    cout << "main: var5: ";
    cout.flush();
    var5.print();
    cout << endl;

    return EXIT_SUCCESS;
}

/* Ref: http://www.cplusplus.com/doc/tutorial/polymorphism/
 * A program that shows the usage of C++ polymorphism. */

#include <iostream>
#include <string>

using namespace std;

// Define Abstract Base Classes (ABC's)
// ==== NOTES ====
// ABC's are classes that include pure virtual functions
// ABC's cannot be initialized
class Polygon {
   private:
    float areaState;

   public:
    Polygon(float area) {
        areaState = area;
    }

    virtual float area() {
        return areaState;
    }

    virtual string strRepr() {
        string repr = "{ (Polygon) \n";
        {
            repr += "\tarea: " + to_string(areaState) + "\n";
        }
        repr += "}";
        return repr;
    }

    // Define pure virtual functions
    virtual void print() = 0;
};

class Rect : public Polygon {
   private:
    float widthState;
    float heightState;

   public:
    Rect(float width, float height) : Polygon(width * height) {
        widthState = width;
        heightState = height;
    }

    float width() {
        return widthState;
    }

    float height() {
        return heightState;
    }

    string strRepr() {
        string repr = Polygon::strRepr();
        repr += "{ (Rect) \n";
        {
            repr += "\twidth: " + to_string(widthState) + "\n";
            repr += "\theight: " + to_string(heightState) + "\n";
        }
        repr += "}";
        return repr;
    }

    void print() {
        cout << strRepr();
        cout.flush();
    }
};

class Trig : public Polygon {
   private:
    float baseState;
    float heightState;

   public:
    Trig(float base, float height) : Polygon(base * height / 2.0f) {
        baseState = base;
        heightState = height;
    }

    float base() {
        return baseState;
    }

    float height() {
        return heightState;
    }

    string strRepr() {
        string repr = Polygon::strRepr();
        repr += "{ (Trig) \n";
        {
            repr += "\tbase: " + to_string(baseState) + "\n";
            repr += "\theight: " + to_string(heightState) + "\n";
        }
        repr += "}";
        return repr;
    }

    void print() {
        cout << strRepr();
        cout.flush();
    }
};

// <<<< main function >>>>
int main(int argc, char **argv) {
    Rect var1(3, 4);
    Trig var2(4, 6);
    cout << "main: var1:\n"
         << var1.strRepr() << endl;
    cout << "main: var2:\n"
         << var2.strRepr() << endl;

    // Use polymorphism
    Polygon *ptr1 = &var1;
    Polygon *ptr2 = &var2;
    cout << "main: ptr1: \n"
         << "*";
    cout.flush();
    ptr1->print();
    cout << endl;
    cout << "main: ptr2: \n"
         << "*";
    cout.flush();
    ptr2->print();
    cout << endl;

    // Use polymorphism with dynamic memory
    Polygon *ptr3 = new Rect(6, 7);
    Polygon *ptr4 = new Trig(7, 12);
    cout << "main: ptr3:\n"
         << "*" << ptr3->strRepr() << endl;
    cout << "main: ptr4:\n"
         << "*" << ptr4->strRepr() << endl;

    // Invoke shadowed functions in child classes
    cout << "main: ptr3 as Polygon:\n"
         << "*" << ptr3->Polygon::strRepr() << endl;
    cout << "main: ptr4 as Polygon:\n"
         << "*" << ptr4->Polygon::strRepr() << endl;

    delete ptr4;
    delete ptr3;

    return EXIT_SUCCESS;
}

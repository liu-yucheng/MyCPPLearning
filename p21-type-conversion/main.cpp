/* Ref: http://www.cplusplus.com/doc/tutorial/typecasting/
 * A program that shows the usage of C++ type conversion. */

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

// Declare class names
class I16;
class I32;

class I16 {
   private:
    short valState;

   public:
    I16();
    I16(short);

    // Declare explicit conversion constructor
    explicit I16(I32 &);
    // Declare assignment conversion operator
    I16 &operator=(I32 &);

    short val();
    short val(short);

    string strRepr();
};

class I32 {
   private:
    int valState;

   public:
    I32();
    I32(int);

    // Declare implicit conversion constructor
    I32(I16 &);
    I32 &operator=(I16 &);
    // Declare type-conversion operator
    operator I16();

    int val();
    int val(int);

    string strRepr();
};

// Implement I16 methods
I16::I16() {
    valState = 0;
}
I16::I16(short val) {
    valState = val;
}

I16::I16(I32 &target) {
    cout << "I16: invoked I16::I16(I32 &)" << endl;
    valState = (short)target.val();
}
I16 &I16::operator=(I32 &target) {
    cout << "I16: invoked I16::operator=(I32 &)" << endl;
    valState = (short)target.val();
    return *this;
}

short I16::val() {
    return valState;
}
short I16::val(short newVal) {
    short oldVal = valState;
    valState = newVal;
    return oldVal;
}

string I16::strRepr() {
    string repr = "{ (I16) ";
    repr += "val: " + to_string(valState) + " ";
    repr += "}";
    return repr;
}

// Implement I32 methods
I32::I32() {
    valState = 0;
}
I32::I32(int val) {
    valState = val;
}

I32::I32(I16 &target) {
    cout << "I32: invoked I32::I32(I16 &)" << endl;
    valState = target.val();
}
I32 &I32::operator=(I16 &target) {
    cout << "I32: invoked I32::operator=(I16 &)" << endl;
    valState = target.val();
    return *this;
}
I32::operator I16() {
    cout << "I32: invoked I32::I16()" << endl;
    return I16((short)valState);
}

int I32::val() {
    return valState;
}
int I32::val(int newVal) {
    int oldVal = valState;
    valState = newVal;
    return oldVal;
}

string I32::strRepr() {
    string repr = "{ (I32) ";
    repr += "val: " + to_string(valState) + " ";
    repr += "}";
    return repr;
}

class Parent {
   public:
    virtual string strRepr() {
        return "{ (Parent) }";
    }
};

class Child : public Parent {
   public:
    string strRepr() {
        return Parent::strRepr() + "{ (Child) }";
    }
};

void print(char *text) {
    cout << "print: " << text << endl;
}

// <<<< main function >>>>
int main(int argc, char **argv) {
    short var1 = 1;
    cout << "main: var1: " << var1 << endl;
    // Use implicit primitive type conversions
    int var2 = var1;
    cout << "main: var2: " << var2 << endl;

    I16 var3(3);
    cout << "main: var3: " << var3.strRepr() << endl;
    // Use implicit conversion constructors (I32::I32(I16 &))
    I32 var4 = var3;
    cout << "main: var4: " << var4.strRepr() << endl;

    I32 var5(65535);
    cout << "main: var5: " << var5.strRepr() << endl;
    // Use type-conversion operator (I32::operator I16())
    I16 var6 = var5;
    cout << "main: var6: " << var6.strRepr() << endl;

    I16 var7(7);
    I32 var8;
    // Use assignment conversion operator (I32::operator=(I16 &))
    var8 = var7;
    cout << "main: var8: " << var8.strRepr() << endl;

    I32 var9(9);
    I16 var10;
    // Use assignment conversion operator (I16::operator=(I32 &))
    var10 = var9;
    cout << "main: var10: " << var10.strRepr() << endl;

    I32 var11(11);
    // Use explicit conversion constructors (I16::I16(I32 &))
    I16 var12(var11);
    cout << "main: var12: " << var12.strRepr() << endl;

    Parent *ptr1 = new Parent;
    Parent *ptr2 = new Child;
    // Use dynamic casts (runtime-checked)
    Child *ptr3 = dynamic_cast<Child *>(ptr1);
    if (ptr3 == nullptr) {
        cout << "main: ptr3: nullptr" << endl;
    } else {
        cout << "main: ptr3: " << ptr3->strRepr() << endl;
    }
    Child *ptr4 = dynamic_cast<Child *>(ptr2);
    if (ptr4 == nullptr) {
        cout << "main: ptr4: nullptr" << endl;
    } else {
        cout << "main: ptr4: " << ptr4->strRepr() << endl;
    }
    delete ptr2;
    delete ptr1;

    Parent *ptr5 = new Parent;
    Parent *ptr6 = new Child;
    // Use static casts (runtime-unchecked)
    Child *ptr7 = static_cast<Child *>(ptr5);
    if (ptr7 == nullptr) {
        cout << "main: ptr7: nullptr" << endl;
    } else {
        cout << "main: ptr7: " << ptr7->strRepr() << endl;
    }
    Child *ptr8 = static_cast<Child *>(ptr6);
    if (ptr8 == nullptr) {
        cout << "main: ptr8: nullptr" << endl;
    } else {
        cout << "main: ptr8: " << ptr8->strRepr() << endl;
    }
    delete ptr6;
    delete ptr5;

    Parent *ptr9 = new Parent;
    Parent *ptr10 = new Child;
    // Use reinterpret casts (unchecked)
    Child *ptr11 = reinterpret_cast<Child *>(ptr9);
    if (ptr11 == nullptr) {
        cout << "main: ptr11: nullptr" << endl;
    } else {
        cout << "main: ptr11: " << ptr11->strRepr() << endl;
    }
    Child *ptr12 = reinterpret_cast<Child *>(ptr10);
    if (ptr12 == nullptr) {
        cout << "main: ptr12: nullptr" << endl;
    } else {
        cout << "main: ptr12: " << ptr12->strRepr() << endl;
    }
    delete ptr10;
    delete ptr9;

    // Use const cast (which tweaks the const identifier)
    const char *ptr13 = "text";
    print(const_cast<char *>(ptr13));

    // Use typeid
    // NOTE: Type names are implementation-dependent
    // NOTE: Run "./main.x | c++filt -t" to see more readable type names
    int var13 = 13;
    cout << "main: typeid(var13).name(): " << typeid(var13).name() << endl;
    int *ptr14 = &var13;
    cout << "main: typeid(ptr14).name(): " << typeid(ptr14).name() << endl;
    Parent var14;
    cout << "main: typeid(var14).name(): " << typeid(var14).name() << endl;
    Child var15;
    cout << "main: typeid(var15).name(): " << typeid(var15).name() << endl;
    Parent *ptr15 = &var14;
    cout << "main: typeid(ptr15).name(): " << typeid(ptr15).name() << endl;
    Child *ptr16 = &var15;
    cout << "main: typeid(ptr16).name(): " << typeid(ptr16).name() << endl;

    return EXIT_SUCCESS;
}

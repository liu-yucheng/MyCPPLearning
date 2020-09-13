/* Ref: http://www.cplusplus.com/doc/tutorial/other_data_types/
 * A program that shows the usage of C++ custom data types. */

#include <iostream>
#include <string>

using namespace std;

// Declare custom data types
typedef char i8;
typedef short i16;
using i32 = long;
using i64 = long long;

// Declare unions
union WideChar {
    char c8;
    short c16;
};

// Declare enums
enum RGB {
    RED = 0,
    GREEN,
    BLUE
};

string strOfRGB(RGB color) {
    string result;
    switch (color) {
        case RED:
            result = "RED";
            break;
        case GREEN:
            result = "GREEN";
            break;
        case BLUE:
            result = "BLUE";
            break;
        default:
            result = "UNDEFINED";
            break;
    }
    return result;
}

// Declare enum class
enum class RGB2 : char {
    RED,
    GREEN,
    BLUE
};

string strOfRGB2(RGB2 color) {
    string result;
    if (color == RGB2::RED) {
        result = "RGB2::RED";
    } else if (color == RGB2::GREEN) {
        result = "RGB2::GREEN";
    } else if (color == RGB2::BLUE) {
        result = "RGB2::BLUE";
    }
    return result;
}

int main(int argc, char **argv) {
    // Declare variables of custom types
    i8 var1 = 1;
    cout << "main: var1: " << (int)var1 << endl;

    i16 var2 = 2;
    cout << "main: var2: " << (int)var2 << endl;

    i32 var3 = 3;
    cout << "main: var3: " << var3 << endl;

    i32 var4 = 4;
    cout << "main: var4: " << var4 << endl;

    WideChar var5;
    var5.c8 = 127;
    cout << "main: var5(c8): " << (int)var5.c8 << endl;
    cout << "main: var5(c16): " << var5.c16 << endl;
    var5.c16 = 32767;
    cout << "main: var5(c8): " << (int)var5.c8 << endl;
    cout << "main: var5(c16): " << var5.c16 << endl;

    // Declare anonymous unions
    union {
        int i32;
        float f32;
    } var6;
    var6.i32 = 6;
    cout << "main: var6(i32): " << var6.i32 << endl;
    cout << "main: var6(f32): " << var6.f32 << endl;
    var6.f32 = 6.6f;
    cout << "main: var6(i32): " << var6.i32 << endl;
    cout << "main: var6(f32): " << var6.f32 << endl;

    // Use enums
    RGB color1 = RED;
    cout << "main: color1: " << strOfRGB(color1) << endl;

    // Use enum classes
    RGB2 color2 = RGB2::GREEN;
    cout << "main: color2: " << strOfRGB2(color2) << endl;

    return EXIT_SUCCESS;
}

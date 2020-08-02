/* Ref: http://www.cplusplus.com/doc/tutorial/operators/
 * A program that shows the usage of operators. */

#include <iostream>

using namespace std;

static void assignment();
static void arithmetic();
static void compound();
static void crements();
static void comparison();
static void logical();
static void ternary();
static void comma();
static void bitwise();
static void typeCast();
static void sizeofOp();

int main(int argc, char **argv) {
    assignment();
    arithmetic();
    compound();
    crements();
    comparison();
    logical();
    ternary();
    comma();
    bitwise();
    typeCast();
    sizeofOp();
    return 0;
}

static void assignment() {
    cout << "==== assignment ====" << endl;

    int a = 10, b = 4;
    a = b;
    b = 7;
    // Verify that a:4, b:7
    cout << "a:" << a << ", ";
    cout << "b:" << b << endl;

    int x, y;
    y = 2 + (x = 5);
    // Verify that x:5, y:7
    cout << "x:" << x << ", ";
    cout << "y:" << y << endl;
    x = 5;
    y = 2 + x;
    // Verify that x:5, y:7
    cout << "x:" << x << ", ";
    cout << "y:" << y << endl;

    int z;
    x = y = z = 5;
    // Verify that x:5, y:5, z:5
    cout << "x:" << x << ", ";
    cout << "y:" << y << ", ";
    cout << "z:" << z << endl;
}

static void arithmetic() {
    cout << "==== arithmetic ====" << endl;

    int x = 11 % 3;
    // Verify that x:2
    cout << "x:" << x << endl;
}

static void compound() {
    cout << "==== compound ====" << endl;

    int a, b;
    a = b = 3;
    a += 2;
    // Verify that a:5, b:3
    cout << "a:" << a << ", ";
    cout << "b:" << b << endl;
}

static void crements() {
    cout << "==== crements ====" << endl;

    int x, y;
    x = 3;
    y = ++x;
    // Verify that x:4, y:4
    cout << "x:" << x << ", ";
    cout << "y:" << y << endl;
    x = 3;
    y = x++;
    // Verify that x:4, y:3
    cout << "x:" << x << ", ";
    cout << "y:" << y << endl;
}

static void comparison() {
    cout << "==== comparison ====" << endl;

    // Verify some comparison results
    // 7==5: 0
    cout << "7==5: " << (7 == 5) << endl;
    // 5>4: 1
    cout << "5>4: " << (5 > 4) << endl;
    // 3!=2: 1
    cout << "3!=2: " << (3 != 2) << endl;
    // 6>=6: 1
    cout << "6>=6: " << (6 >= 6) << endl;
    // 5 < 5: 0
    cout << "5<5: " << (5 < 5) << endl;

    // Verify more comparison results
    int a = 2, b = 3, c = 6;
    // a==5: 0
    cout << "a==5: " << (a == 5) << endl;
    // a*b>=c: 1
    cout << "a*b>=c: " << (a * b >= c) << endl;
    // b+4>a*c: 0
    cout << "b+4>a*c: " << (b + 4 > a * c) << endl;
    // (b=2)==a: 1
    cout << "(b=2)==a: " << ((b = 2) == a) << endl;
}

static void logical() {
    cout << "==== logical ====" << endl;

    // Verify some logical expressions
    // !(5==5): 0
    cout << "!(5==5): " << !(5 == 5) << endl;
    // !(6<=4): 1
    cout << "!(6<=4): " << !(6 <= 4) << endl;
    // !true: 0
    cout << "!true: " << !true << endl;
    // !false: 1
    cout << "!false: " << !false << endl;

    // Verify more logical expressions
    // ((5==5)&&(3>6)): 0
    cout << "((5==5)&&(3>6)): " << ((5 == 5) && (3 > 6)) << endl;
    // ((5==5)||(3>6)): 1
    cout << "((5==5)||(3>6)): " << ((5 == 5) || (3 > 6)) << endl;
}

static void ternary() {
    cout << "==== ternary ====" << endl;

    int a = 2, b = 7, c;
    c = a > b ? a : b;
    // Verify that c:7
    cout << "c:" << c << endl;
}

static void comma() {
    cout << "==== comma ====" << endl;

    int a, b;
    a = (b = 3, b + 2);
    // Verify that a:5, b:3
    cout << "a:" << a << ", ";
    cout << "b:" << b << endl;
}

static void bitwise() {
    cout << "==== bitwise ====" << endl;

    int x, y, z;
    x = 0x3;
    y = 0x6;
    z = x & y;
    // Verify that z:2
    cout << "z:" << z << endl;

    z = x | y;
    // Verify that z:7
    cout << "z:" << z << endl;

    z = x ^ y;
    // Verify that z:5
    cout << "z:" << z << endl;

    z = ~x;
    // Verify that z:-4
    cout << "z:" << z << endl;

    z = x << 1;
    // Verify that z:6
    cout << "z:" << z << endl;

    z = y >> 1;
    // Verify that z:3
    cout << "z:" << z << endl;
}

static void typeCast() {
    cout << "==== typeCast ====" << endl;

    int i;
    float f = 3.14;

    i = (int)f;
    // Verify that i:3
    cout << "i:" << i << endl;

    i = int(f);
    // Verify that i:3
    cout << "i:" << i << endl;
}

static void sizeofOp() {
    cout << "==== sizeofOp ====" << endl;

    int x;

    x = sizeof(char);
    // Verify that x:1
    cout << "x:" << x << endl;
}

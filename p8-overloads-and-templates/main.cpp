/* Ref: http://www.cplusplus.com/doc/tutorial/functions2
 * A program that shows the usage of C++ function overloads and templates. */

/* Copyright 2022 Yucheng Liu. GNU GPL3 license.
 * GNU GPL3 license copy: https://www.gnu.org/licenses/gpl-3.0.txt */

#include <iostream>

using namespace std;

int mult(int, int);
float mult(float, float);

template <typename T>
T mult(T, T);

template <int>
void inc(int &a);

int main(int argc, char **argv) {
    // Use overloaded function (int mult)
    int a = 2, b = 3, c;
    c = mult(a, b);
    cout << "int mult:\t"
         << a << '*' << b << '=' << c;
    cout << endl;

    // Use overloaded function (float mult)
    float a2 = 1.5f, b2 = 2.5f, c2;
    c2 = mult(a2, b2);
    cout << "float mult:\t"
         << a2 << " * " << b2 << " = " << c2;
    cout << endl;

    // Use function template (template long mult)
    long (*multLong)(long, long) = mult<long>;
    long l1 = 3l, l2 = 4l, l3;
    l3 = multLong(l1, l2);
    cout << "template long mult:\t"
         << l1 << '*' << l2 << '=' << l3;
    cout << endl;

    // Use function template (template double mult)
    double (*multDouble)(double, double) = mult<double>;
    double d1 = 2.5, d2 = 3.5, d3;
    d3 = multDouble(d1, d2);
    cout << "template double mult:\t"
         << d1 << " * " << d2 << " = " << d3;
    cout << endl;

    // Use function template with non-type arguments (template 2 inc)
    void (*incBy2)(int &) = inc<2>;
    int a3 = 2;
    cout << "before template 2 inc:\ta3:" << a3;
    cout << endl;
    incBy2(a3);
    cout << "after template 2 inc:\ta3:" << a3;
    cout << endl;

    // Use function template with non-type arguments (template 4 inc)
    void (*incBy4)(int &) = inc<4>;
    int a4 = 4;
    cout << "before template 4 inc:\ta4:" << a4;
    cout << endl;
    incBy4(a4);
    cout << "after template 4 inc:\ta4:" << a4;
    cout << endl;

    return 0;
}

int mult(int a, int b) {
    return a * b;
}

float mult(float a, float b) {
    return a * b;
}

template <typename T>
T mult(T t1, T t2) {
    return t1 * t2;
}

template <int unit>
void inc(int &a) {
    a += unit;
}

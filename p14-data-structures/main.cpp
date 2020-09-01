/* Ref: http://www.cplusplus.com/doc/tutorial/structures/
 * A program that shows the usage of C++ data structures. */

#include <iostream>
#include <string>

using namespace std;

// Declare a struct data structure
struct Point2D {
    int x;
    int y;
};

// Declare a nested struct data structure (Linked List)
struct LList {
    int val;
    LList *next;
};

Point2D makePoint2D(int, int);
void editPoint2D(Point2D *, int, int);
string strOfPoint2D(Point2D &);
LList *lListOfArray(int *, int);
string strOfLListPtr(LList *);
void deleteLList(LList *);

int main(int argc, char **argv) {
    // Make a Point2D variable
    Point2D p1 = makePoint2D(0, 0);
    // Print the Point2D variable
    cout << "main: p1: " << strOfPoint2D(p1) << endl;

    // Make a dynamically allocated Point2D variable
    Point2D *p2Ptr = new Point2D;
    editPoint2D(p2Ptr, 1, 1);
    // Print the dynamically allocated Point2D variable
    cout << "main: p2Ptr: *" << strOfPoint2D(*p2Ptr) << endl;
    // Delete variable after last use
    delete p2Ptr;

    // Make a dynamically allocated variable of nested data structure type
    int a1[5] = {1, 2, 3, 4, 5};
    LList *l1Ptr = lListOfArray(a1, 5);
    // Print the dynamically allocated nested data structure
    cout << "main: l1Ptr: " << strOfLListPtr(l1Ptr) << endl;
    deleteLList(l1Ptr);

    return EXIT_SUCCESS;
}

Point2D makePoint2D(int x, int y) {
    // Initialize custom data structures
    Point2D point;
    point.x = x;
    point.y = y;
    return point;
}

void editPoint2D(Point2D *pointPtr, int x, int y) {
    // Access custom data structures through their pointers
    // Equivalent to (*pointPtr).x = x
    pointPtr->x = x;
    // Equivalent to (*pointPtr).y = y
    pointPtr->y = y;
}

string strOfPoint2D(Point2D &point) {
    // Access custom data structures
    string result = "Point2D{";
    result += "x: " + to_string(point.x) + ", ";
    result += "y: " + to_string(point.y);
    result += "}";
    return result;
}

LList *lListOfArray(int *array, int count) {
    if (count <= 0) {
        return  nullptr;
    }
    // Initialize nested data structures
    LList *list = new LList;
    LList *cur = list;
    for (int iter = 0; iter < count; iter += 1) {
        cur->val = array[iter];
        if (iter < count - 1) {
            cur->next = new LList;
        } else {
            cur->next = nullptr;
        }

        cur = cur->next;
    }
    return list;
}

string strOfLListPtr(LList *listPtr) {
    // Access nested data structures
    string result = "*LList[";
    LList *cur = listPtr;
    while (cur != nullptr) {
        result += to_string(cur->val);
        if (cur->next != nullptr) {
            result += ", ";
        }
        cur = cur-> next;
    }
    result += "]";
    return result;
}

void deleteLList(LList *listPtr) {
    // Delete dynamically allocated elements of nested data structures
    LList *cur, *nxt;
    cur = listPtr;
    while (cur != nullptr) {
        nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}

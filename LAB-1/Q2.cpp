#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10;
    float b = 3.14;
    double c = 6.28;
    char d = 'A';
    string e = "Hello";

    cout << "Value of int a: " << a << ", Address: " << &a << ", Size: " << sizeof(a) << endl;
    cout << "Value of float b: " << b << ", Address: " << &b << ", Size: " << sizeof(b) << endl;
    cout << "Value of double c: " << c << ", Address: " << &c << ", Size: " << sizeof(c) << endl;
    cout << "Value of char d: " << d << ", Address: " << (void *)&d << ", Size: " << sizeof(d) << endl;
    cout << "Value of string e: " << e << ", Address: " << &e << ", Size: " << sizeof(e) << endl;

    return 0;
}

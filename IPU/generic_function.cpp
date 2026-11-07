#include <iostream>
using namespace std;

// Function template to calculate square
template <class T>
T square(T num)
{
    return num * num;
}

int main()
{
    int i = 5;
    float f = 2.5f;
    double d = 4.2;

    cout << "Square of integer " << i << " = " << square(i) << endl;
    cout << "Square of float " << f << " = " << square(f) << endl;
    cout << "Square of double " << d << " = " << square(d) << endl;

    return 0;
}
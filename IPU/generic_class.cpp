#include <iostream>
using namespace std;

template <class T>
class Larger
{
private:
    T a, b;

public:
    Larger(T x, T y)
    {
        a = x;
        b = y;
    }

    ~Larger()
    {
        // Destructor
    }

    T findLarger()
    {
        return (a > b) ? a : b;
    }
};

int main()
{
    Larger<int> obj1(10, 20);
    cout << "Larger integer value: " << obj1.findLarger() << endl;

    Larger<float> obj2(5.5f, 3.2f);
    cout << "Larger float value: " << obj2.findLarger() << endl;

    Larger<double> obj3(12.75, 15.25);
    cout << "Larger double value: " << obj3.findLarger() << endl;

    return 0;
}
#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
    int arr[10];

public:
    SafeArray() {
        for (int i = 0; i < 10; i++)
            arr[i] = 0;
    }

    void set(int index, int value) {
        if (index < 0 || index >= 10)
            throw out_of_range("Invalid array index in set()");
        arr[index] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= 10)
            throw out_of_range("Invalid array index in get()");
        return arr[index];
    }
};

int main() {
    SafeArray a;
    int index, value;

    try {
        cout << "Enter index (0 to 9): ";
        cin >> index;
        cout << "Enter value: ";
        cin >> value;

        a.set(index, value);
        cout << "Value stored successfully.\n";
        cout << "Value at index " << index << " = " << a.get(index) << '\n';

        // Uncomment the next line to test an invalid index:
        // cout << a.get(10) << '\n';
    }
    catch (const out_of_range &e) {
        cout << "Exception caught: " << e.what() << '\n';
    }
    return 0;
}
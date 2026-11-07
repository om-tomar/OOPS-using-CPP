#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    string name, sex;
    int age;
    float height, weight;

public:
    void readData() {
        cout << "Enter name: ";
        getline(cin >> ws, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter sex: ";
        cin >> sex;
        cout << "Enter height (in cm): ";
        cin >> height;
        cout << "Enter weight (in kg): ";
        cin >> weight;
    }

    void show() const {
        cout << "\n----- Student Details -----\n";
        cout << "Name   : " << name << '\n';
        cout << "Age    : " << age << '\n';
        cout << "Sex    : " << sex << '\n';
        cout << "Height : " << height << " cm\n";
        cout << "Weight : " << weight << " kg\n";
    }

    // Serialize each field; never write the raw std::string object.
    void write(ofstream &out) const {
        size_t n = name.size();
        out.write(reinterpret_cast<const char*>(&n), sizeof(n));
        out.write(name.data(), static_cast<streamsize>(n));
        out.write(reinterpret_cast<const char*>(&age), sizeof(age));

        n = sex.size();
        out.write(reinterpret_cast<const char*>(&n), sizeof(n));
        out.write(sex.data(), static_cast<streamsize>(n));
        out.write(reinterpret_cast<const char*>(&height), sizeof(height));
        out.write(reinterpret_cast<const char*>(&weight), sizeof(weight));
    }

    bool read(ifstream &in) {
        size_t n;
        if (!in.read(reinterpret_cast<char*>(&n), sizeof(n))) return false;
        name.resize(n);
        if (n && !in.read(&name[0], static_cast<streamsize>(n))) return false;
        if (!in.read(reinterpret_cast<char*>(&age), sizeof(age))) return false;

        if (!in.read(reinterpret_cast<char*>(&n), sizeof(n))) return false;
        sex.resize(n);
        if (n && !in.read(&sex[0], static_cast<streamsize>(n))) return false;
        if (!in.read(reinterpret_cast<char*>(&height), sizeof(height))) return false;
        if (!in.read(reinterpret_cast<char*>(&weight), sizeof(weight))) return false;
        return true;
    }
};

int main() {
    Student s1, s2;
    cout << "Enter student details:\n";
    s1.readData();

    ofstream outFile("student.dat", ios::binary);
    if (!outFile) {
        cout << "Unable to open file for writing.\n";
        return 1;
    }
    s1.write(outFile);
    outFile.close();

    ifstream inFile("student.dat", ios::binary);
    if (!inFile) {
        cout << "Unable to open file for reading.\n";
        return 1;
    }
    if (s2.read(inFile)) {
        cout << "\nStudent object retrieved from file:\n";
        s2.show();
    } else {
        cout << "Error while reading student data.\n";
    }
    inFile.close();
    return 0;
}
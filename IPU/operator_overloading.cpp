#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class String
{
private:
    char *str;

public:
    // Constructor
    String(const char *s = "")
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy constructor
    String(const String &s)
    {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }

    // Destructor
    ~String()
    {
        delete[] str;
    }

    // Overload + operator for concatenation
    String operator+(const String &s) const
    {
        char *temp = new char[strlen(str) + strlen(s.str) + 1];
        strcpy(temp, str);
        strcat(temp, s.str);
        String result(temp);
        delete[] temp;
        return result;
    }

    // Overload = operator for copying
    String& operator=(const String &s)
    {
        if (this != &s)
        {
            char *temp = new char[strlen(s.str) + 1];
            strcpy(temp, s.str);
            delete[] str;
            str = temp;
        }
        return *this;
    }

    // Overload <= operator for comparison
    bool operator<=(const String &s) const
    {
        return strcmp(str, s.str) <= 0;
    }

    void display() const
    {
        cout << str << endl;
    }

    void displayLength() const
    {
        cout << "Length: " << strlen(str) << endl;
    }

    void toLower()
    {
        for (int i = 0; str[i] != '\0'; i++)
            str[i] = tolower((unsigned char)str[i]);
    }

    void toUpper()
    {
        for (int i = 0; str[i] != '\0'; i++)
            str[i] = toupper((unsigned char)str[i]);
    }
};

int main()
{
    String s1("Hello");
    String s2("World");

    cout << "First string: ";
    s1.display();

    cout << "Second string: ";
    s2.display();

    String s3 = s1 + s2;
    cout << "Concatenation: ";
    s3.display();

    String s4;
    s4 = s1;
    cout << "Copied string: ";
    s4.display();

    cout << "Comparison (s1 <= s2): ";
    cout << (s1 <= s2 ? "True" : "False") << endl;

    s1.displayLength();

    s1.toUpper();
    cout << "Uppercase: ";
    s1.display();

    s2.toLower();
    cout << "Lowercase: ";
    s2.display();

    return 0;
}
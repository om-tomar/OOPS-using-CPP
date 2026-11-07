#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile)
    {
        cout << "Error opening input.txt" << endl;
        return 1;
    }

    if (!outFile)
    {
        cout << "Error creating output.txt" << endl;
        return 1;
    }

    char ch;

    while (inFile.get(ch))
    {
        // Skip all requested whitespace characters
        if (ch != ' '  && ch != '\t' && ch != '\v' &&
            ch != '\n' && ch != '\r' && ch != '\f')
        {
            outFile.put(ch);
        }
    }

    inFile.close();
    outFile.close();

    cout << "Whitespace removed successfully." << endl;
    cout << "Result written to output.txt" << endl;

    return 0;
}
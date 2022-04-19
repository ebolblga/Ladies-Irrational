#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void main()
{
    string pathA = "..\\a.txt";
    string pathB = "..\\b.txt";
    ifstream fileA;
    fileA.open(pathA);
   
    string line;

    while (getline(fileA, line))
    {
        ifstream fileB;
        fileB.open(pathB);
        string line2;

        while (getline(fileB, line2))
            cout << line << "\t" << line2 << '\n';
    }
    cout << endl;
}
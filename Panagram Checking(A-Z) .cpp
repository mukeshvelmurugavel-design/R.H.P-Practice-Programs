#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    int upper = 0;

    for (char ch : str) {
        if (ch >= 'A' && ch <= 'Z') {
            upper |= (1 << (ch - 'A'));
        }
    }

    int allLetters = (1 << 26) - 1;

    if (upper == allLetters)
        cout << "True";
    else
        cout << "False";

    return 0;
}
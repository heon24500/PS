#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        cout << str[i] - 'A' + 1 << " ";
    }

    return 0;
}
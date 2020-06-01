#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string text, key;
    getline(cin, text);
    getline(cin, key);

    while (text.length() > key.length()) {
        key += key;
    }

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') cout << " ";
        else {
            int diff = key[i] - 'a' + 1;
            char ch = text[i] - diff;
            if (ch < 'a') ch += 26;
            cout << ch;
        }
    }
}
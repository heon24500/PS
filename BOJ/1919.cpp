#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    char a1[26], a2[26];
    for (int i = 0; i < 26; i++) {
        a1[i] = 0;
        a2[i] = 0;
    }

    for (int i = 0; i < str1.length(); i++) {
        int num = str1[i] - 'a';
        a1[num]++;
    }
    for (int i = 0; i < str2.length(); i++) {
        int num = str2[i] - 'a';
        a2[num]++;
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (a1[i] != a2[i]) cnt += abs(a1[i] - a2[i]);
    }

    cout << cnt;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ch[26];
    for (int i = 0; i < 26; i++) {
        ch[i] = 0;
    }

    string str;
    while (cin >> str) {
        for (int i = 0; i < str.length(); i++) {
            ch[str[i] - 'a']++;
        }
    }

    vector<int> max_num;
    int max = 0;
    for (int i = 0; i < 26; i++) {
        if (max < ch[i]) {
            max = ch[i];
            max_num.clear();
            max_num.push_back(i);
        }
        else if (max == ch[i]) max_num.push_back(i);
    }

    sort(max_num.begin(), max_num.end());
    for (int i = 0; i < max_num.size(); i++) {
        char ret = max_num[i] + 'a';
        cout << ret;
    }
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, str2;
    cin >> str;

    int N = stoi(str);
    for (int i = 1; i <= N; i++) {
        str2 += to_string(i);
    }

    int j = 0, ret = 0;
    for (int i = 0; i < str2.length(); i++) {
        if (str2[i] == str[j]) {
            if (ret == 0) {
                ret = i + 1;
                j++;
            }
            else j++;
        }
        else {
            j = 0;
            ret = 0;
        }

        if (j == str.length()) {
            cout << ret;
            break;
        }
    }
}
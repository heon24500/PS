#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str;
    vector<int> result;
    cin >> str;

    int j = 1;
    int num = 0;
    int val = 1;

    if ((str.length() == 1) && (str[0] == '0')) cout << 0;

    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == '1') num += val;

        if ((j % 3) == 0) {
            result.push_back(num);
            num = 0;
            val = 1;
        }
        else val *= 2;

        j++;
    }

    if (num != 0) result.push_back(num);

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> plusString(string str1, string str2) {
    vector<int> ret;
    int len1 = str1.length(), len2 = str2.length();
    int carry = 0;

    if (len1 > len2) {
        while (len2) {
            int int1 = str1[len1 - 1] - '0', int2 = str2[len2 - 1] - '0';
            int result = int1 + int2 + carry;

            if (result >= 10) {
                result -= 10;
                carry = 1;
            }
            else carry = 0;

            ret.push_back(result);
            len1--;
            len2--;
        }
        while (len1) {
            int result = str1[len1 - 1] - '0' + carry;

            if (result >= 10) {
                result -= 10;
                carry = 1;
            }
            else carry = 0;

            ret.push_back(result);
            len1--;
        }
    }
    else if (len1 < len2) {
        while (len1) {
            int int1 = str1[len1 - 1] - '0', int2 = str2[len2 - 1] - '0';
            int result = int1 + int2 + carry;

            if (result >= 10) {
                result -= 10;
                carry = 1;
            }
            else carry = 0;

            ret.push_back(result);
            len1--;
            len2--;
        }
        while (len2) {
            int result = str2[len2 - 1] - '0' + carry;

            if (result >= 10) {
                result -= 10;
                carry = 1;
            }
            else carry = 0;

            ret.push_back(result);
            len2--;
        }
    }
    else {
        while (len1) {
            int int1 = str1[len1 - 1] - '0', int2 = str2[len2 - 1] - '0';
            int result = int1 + int2 + carry;

            if (result >= 10) {
                carry = result / 10;
                result -= 10 * carry;
            }
            else carry = 0;

            ret.push_back(result);
            len1--;
            len2--;
        }

        if (carry > 0) ret.push_back(carry);
    }

    return ret;
}

int main() {
    vector<int> result;
    string str1, str2;
    char oper;
    cin >> str1 >> oper >> str2;

    if (oper == '+') {
        result = plusString(str1, str2);
        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i];
        }
    }
    else {
        int len = (str1.length() - 1) + (str2.length() - 1);
        cout << '1';
        while (len--) {
            cout << '0';
        }
    }


    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') sum += str[i] - 'A' + 27;
        else sum += str[i] - 'a' + 1;
    }

    bool isPrime = true;
    for (int i = 2; i < sum; i++) {
        if (sum % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) cout << "It is a prime word.";
    else cout << "It is not a prime word.";
}
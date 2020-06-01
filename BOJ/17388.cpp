#include <iostream>
#include <string>
using namespace std;

int main() {
    int part[3], sum = 0;
    string univ[3] = { "Soongsil", "Korea", "Hanyang" };
    for (int i = 0; i < 3; i++) {
        cin >> part[i];
        sum += part[i];
    }

    int min = part[0], num = 0;
    for (int i = 1; i < 3; i++) {
        if (min > part[i]) {
            min = part[i];
            num = i;
        }
    }

    if (sum >= 100) cout << "OK";
    else cout << univ[num];

    return 0;
}
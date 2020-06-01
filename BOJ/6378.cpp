#include <iostream>
#include <string>
using namespace std;

int digit(string s) {
    int sum = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        sum += s[i] - '0';
    }

    if (sum < 10) return sum;
    else return digit(to_string(sum));
}

int main() {
    while (true) {
        char str[1000];
        scanf("%s", str);

        if (str[0] == '0') break;

        printf("%d\n", digit(str));
    }

    return 0;
}
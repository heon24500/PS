#include <iostream>
using namespace std;

int main() {
    int ret = 0, calc = 0, num = 0;
    char prod;
    scanf("%d\n%c", &ret, &prod);

    if (prod == '+') calc = 1;
    else if (prod == '-') calc = 2;
    else if (prod == '*') calc = 3;
    else if (prod == '/') calc = 4;

    while (true) {
        scanf("%d\n%c", &num, &prod);

        if (calc == 1) ret += num;
        else if (calc == 2) ret -= num;
        else if (calc == 3) ret *= num;
        else if (calc == 4) ret /= num;

        calc = 0;

        if (prod == '+') calc = 1;
        else if (prod == '-') calc = 2;
        else if (prod == '*') calc = 3;
        else if (prod == '/') calc = 4;
        else if (prod == '=') break;
    }

    printf("%d", ret);

    return 0;
}
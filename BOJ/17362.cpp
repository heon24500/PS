#include <iostream>
using namespace std;

int main() {
    int n, result[5] = { 1, 2, 3, 4, 5 };
    cin >> n;

    int num = 0;
    int flag = 0;  // flag = 0 : up, flag = 1 : down
    for (int i = 0; i < n; i++) {
        if (flag == 0) {
            num++;
            if (num == 5) flag = 1;
        }
        else {
            num--;
            if (num == 1) flag = 0;
        }
    }

    cout << result[num - 1];

    return 0;
}
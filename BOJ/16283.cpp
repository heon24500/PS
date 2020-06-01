#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, n, w, a_num = 0, b_num = 0;
    cin >> a >> b >> n >> w;

    bool isFound = false, flag = false;
    for (int i = 1; i < n; i++) {
        if (w == (a * i + b * (n - i))) {
            if (!isFound) isFound = true;
            else flag = true;

            a_num = i;
            b_num = n - i;
        }
    }

    if (flag || !isFound) cout << "-1";
    else cout << a_num << " " << b_num;
}
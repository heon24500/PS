#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char* result[3] = { "Accepted", "Wrong Answer", "Why Wrong!!!" };
    int s1, s2, result_case = 0;
    cin >> s1 >> s2;

    while (s1--) {
        int ans, man;
        cin >> ans >> man;
        if (ans != man) {
            result_case = 1;
            break;
        }
    }

    if (result_case == 0) {
        while (s2--) {
            int ans, man;
            cin >> ans >> man;
            if (ans != man) {
                result_case = 2;
                break;
            }
        }
    }

    cout << result[result_case];
}
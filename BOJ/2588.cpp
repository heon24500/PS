#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int result[3];
    int sum = 0;
    int val = 1;

    for (int i = 2; i >= 0; i--) {
        result[i] = stoi(A) * (B[i] - '0');
        cout << result[i] << endl;

        sum += result[i] * val;
        val *= 10;
    }

    cout << sum;

    return 0;
}
#include <iostream>
using namespace std;

long points(int n) {
    if (n == 1) return 5;
    else return points(n - 1) + n * 3 + 1;
}

int main() {
    int N;
    cin >> N;

    long num = points(N);
    cout << num % 45678;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int i = 0, sec = 0;;
    while (N > 0) {
        i++;
        if (N - i < 0) i = 1;
        N -= i;
        sec++;
    }

    cout << sec;
}
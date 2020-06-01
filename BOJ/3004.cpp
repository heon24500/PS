#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int width = 1, height = 1;
    for (int i = N - 1; i >= 0; i--) {
        if ((i % 2) == 0) width++;
        else height++;
    }

    cout << width * height;

    return 0;
}
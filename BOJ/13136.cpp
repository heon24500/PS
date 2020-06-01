#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long R, C, N;
    cin >> R >> C >> N;

    long width, height;
    if ((R % N) == 0) width = R / N;
    else width = R / N + 1;
    if ((C % N) == 0) height = C / N;
    else height = C / N + 1;

    cout << width * height;

    return 0;
}
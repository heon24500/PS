#include <iostream>
using namespace std;

int calcWidth(int a) {
    int ret = a / 4;
    if ((a % 4) != 0) ret++;

    return ret;
}
int calcHeight(int a) {
    int ret = a % 4;

    if (ret == 0) return 4;
    else return ret;
}

int main() {
    int A, B;
    cin >> A >> B;

    int width = calcWidth(A) - calcWidth(B);
    if (width < 0) width = -width;

    int height = calcHeight(A) - calcHeight(B);
    if (height < 0) height = -height;

    cout << width + height;

    return 0;
}
#include <iostream>
using namespace std;

int ys(int sec) {
    if (sec < 30) return 10;
    else return 10 + ys(sec - 30);
}

int ms(int sec) {
    if (sec < 60) return 15;
    else return 15 + ms(sec - 60);
}

int main() {
    int N, ysPay = 0, msPay = 0;
    cin >> N;

    while (N--) {
        int call;
        cin >> call;

        ysPay += ys(call);
        msPay += ms(call);
    }

    if (ysPay < msPay) cout << "Y " << ysPay;
    else if (ysPay == msPay) cout << "Y M " << ysPay;
    else cout << "M " << msPay;

    return 0;
}
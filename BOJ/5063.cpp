#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int r, e, c;
        cin >> r >> e >> c;

        if (r < e - c) cout << "advertise" << endl;
        else if (r > e - c) cout << "do not advertise" << endl;
        else cout << "does not matter" << endl;
    }

    return 0;
}
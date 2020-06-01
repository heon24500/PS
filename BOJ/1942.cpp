#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; i++) {
        int h, m, s;
        char ch;
        cin >> h >> ch >> m >> ch >> s;
        int times1 = h * 10000 + m * 100 + s;
        cin >> h >> ch >> m >> ch >> s;
        int times2 = h * 10000 + m * 100 + s;
        if (times1 > times2) times2 += 240000;

        int cnt = 0;
        int now_h = times1 / 10000;
        int now_m = (times1 - now_h * 10000) / 100;
        int now_s = times1 - now_h * 10000 - now_m * 100;
        while (true) {
            if (now_s >= 60) {
                now_m += now_s / 60;
                now_s %= 60;
            }
            if (now_m >= 60) {
                now_h += now_m / 60;
                now_m %= 60;
            }

            int times = now_h * 10000 + now_m * 100 + now_s;
            if (times % 3 == 0) cnt++;

            now_s++;
            if (times >= times2) break;
        }

        cout << cnt << "\n";
    }
}
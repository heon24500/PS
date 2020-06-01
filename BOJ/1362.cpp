#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i = 0;
    while (true) {
        int o, w;
        cin >> o >> w;

        if (o == 0 && w == 0) break;

        i++;
        while (true) {
            char ch;
            int n;
            cin >> ch >> n;

            if (ch == '#' && n == 0) break;

            if (w > 0) {
                if (ch == 'F') w += n;
                else if (ch == 'E') w -= n;
            }
        }

        if (w <= 0) cout << i << " RIP\n";
        else if (w > o / 2 && w < o * 2) cout << i << " :-)\n";
        else cout << i << " :-(\n";
    }
}
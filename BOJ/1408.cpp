#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char temp;
    int n[3], s[3], r[3];
    cin >> n[0] >> temp >> n[1] >> temp >> n[2];
    cin >> s[0] >> temp >> s[1] >> temp >> s[2];

    if (n[0] > s[0] || (n[0] == s[0] && n[1] > s[1]) || (n[0] == s[0] && n[1] == s[1] && n[2] > s[2])) s[0] += 24;

    r[2] = s[2] - n[2];
    if (r[2] < 0) {
        r[2] += 60;
        s[1]--;
    }

    r[1] = s[1] - n[1];
    if (r[1] < 0) {
        r[1] += 60;
        s[0]--;
    }

    r[0] = s[0] - n[0];

    if (r[0] < 10) cout << 0;
    cout << r[0] << ":";
    if (r[1] < 10) cout << 0;
    cout << r[1] << ":";
    if (r[2] < 10) cout << 0;
    cout << r[2];
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p, w;
    cin >> p >> w;
    cin.ignore();

    string str;
    getline(cin, str);

    int ret = 0, before = 100;
    for (int i = 0; i < str.length(); i++) {
        int times;
        if (str[i] == ' ') times = 1;
        else if (str[i] <= 'C') times = (str[i] - 'A') % 3 + 1;
        else if (str[i] <= 'F') times = (str[i] - 'D') % 3 + 1;
        else if (str[i] <= 'I') times = (str[i] - 'G') % 3 + 1;
        else if (str[i] <= 'L') times = (str[i] - 'J') % 3 + 1;
        else if (str[i] <= 'O') times = (str[i] - 'M') % 3 + 1;
        else if (str[i] <= 'S') times = (str[i] - 'P') % 4 + 1;
        else if (str[i] <= 'V') times = (str[i] - 'T') % 3 + 1;
        else if (str[i] <= 'Z') times = (str[i] - 'W') % 4 + 1;

        int wait = 0;
        if (str[i] != ' ') {
            if (before <= 4 && before == (str[i] - 'A') / 3) wait = w;
            else if (before == 5 && str[i] >= 'P' && str[i] <= 'S') wait = w;
            else if (before == 6 && str[i] >= 'T' && str[i] <= 'V') wait = w;
            else if (before == 7 && str[i] >= 'W' && str[i] <= 'Z') wait = w;
        }
        int push = times * p;
        ret += push + wait;
        if (str[i] <= 'O') before = (str[i] - 'A') / 3;
        else if (str[i] <= 'S') before = 5;
        else if (str[i] <= 'V') before = 6;
        else if (str[i] <= 'Z') before = 7;

        //cout << str[i] << "(" << before << ") : wait " << wait << "s, push " << push << "s(" << times << ") = " << ret << "\n";
    }

    cout << ret;
}
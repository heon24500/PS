#include <iostream>
using namespace std;

int score[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int case_num;
        cin >> case_num;
        for (int j = 0; j < 1000; j++) {
            int s;
            cin >> s;
            score[s]++;
        }

        int max = score[100], ret = 100;
        score[100] = 0;
        for (int j = 99; j >= 0; j--) {
            if (max < score[j]) {
                max = score[j];
                ret = j;
            }
            score[j] = 0;
        }

        cout << "#" << case_num << " " << ret << "\n";
    }

    return 0;
}
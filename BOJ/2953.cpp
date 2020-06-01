#include <iostream>
using namespace std;

int main() {
    int scores[5] = { 0, 0, 0, 0, 0 }, max = 0, maxNum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            int score;
            cin >> score;
            scores[i] += score;
        }

        if (max < scores[i]) {
            max = scores[i];
            maxNum = i;
        }
    }

    cout << maxNum + 1 << " " << max;

    return 0;
}
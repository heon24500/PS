#include <iostream>
using namespace std;

int main() {
    int goCard[3], leaveCard[3], workTime[3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> goCard[j];
        }
        for (int j = 0; j < 3; j++) {
            cin >> leaveCard[j];
        }

        for (int j = 2; j >= 0; j--) {
            if (goCard[j] > leaveCard[j]) {
                leaveCard[j] += 60;
                leaveCard[j - 1]--;
            }

            workTime[j] = leaveCard[j] - goCard[j];
        }

        for (int j = 0; j < 3; j++) cout << workTime[j] << " ";
        cout << endl;
    }

    return 0;
}
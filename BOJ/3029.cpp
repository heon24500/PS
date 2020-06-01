#include <iostream>
using namespace std;

int main() {
    int now_time[3], throw_time[3], wait_time[3];
    scanf("%d:%d:%d\n", &now_time[0], &now_time[1], &now_time[2]);
    scanf("%d:%d:%d", &throw_time[0], &throw_time[1], &throw_time[2]);

    throw_time[0] += 24;
    wait_time[2] = throw_time[2] - now_time[2];
    if (wait_time[2] < 0) {
        wait_time[2] += 60;
        throw_time[1]--;
    }
    wait_time[1] = throw_time[1] - now_time[1];
    if (wait_time[1] < 0) {
        wait_time[1] += 60;
        throw_time[0]--;
    }
    wait_time[0] = throw_time[0] - now_time[0];
    if (wait_time[0] >= 24) wait_time[0] -= 24;

    if ((wait_time[0] == 0) && (wait_time[1] == 0) && (wait_time[2] == 0)) wait_time[0] = 24;

    printf("%.2d:%.2d:%.2d", wait_time[0], wait_time[1], wait_time[2]);

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int skill[4], teamA[3], teamB[3], diff[3];
    for (int i = 0; i < 4; i++) {
        cin >> skill[i];
    }

    teamA[0] = skill[0] + skill[1];
    teamA[1] = skill[0] + skill[2];
    teamA[2] = skill[0] + skill[3];
    teamB[0] = skill[2] + skill[3];
    teamB[1] = skill[1] + skill[3];
    teamB[2] = skill[1] + skill[2];

    for (int i = 0; i < 3; i++) {
        diff[i] = teamA[i] - teamB[i];
        if (diff[i] < 0) diff[i] = -diff[i];
    }

    sort(diff, diff + 3);
    cout << diff[0];

    return 0;
}
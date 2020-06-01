#include <iostream>
using namespace std;

int main() {
    int maxPeople = 0, totalPeople = 0;

    for (int i = 0; i < 4; i++) {
        int inPeople, outPeople;
        cin >> outPeople >> inPeople;

        totalPeople -= outPeople;
        totalPeople += inPeople;

        if (maxPeople < totalPeople) maxPeople = totalPeople;
    }

    cout << maxPeople;

    return 0;
}
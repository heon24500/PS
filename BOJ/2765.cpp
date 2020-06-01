#include <iostream>
using namespace std;

int main() {
    int N = 1;

    while (true) {
        double rad, times, pi = 3.1415927;
        int num;
        cin >> rad >> num >> times;

        if (num == 0) break;

        double distance = ((rad * pi * num) / 12) / 5280;
        double mph = (distance / times) * 60 * 60;

        cout << fixed;
        cout.precision(2);
        cout << "Trip #" << N++ << ": " << distance << " " << mph << endl;
    }

    return 0;
}
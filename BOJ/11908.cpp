#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, sum = 0;
    vector<int> c;
    scanf("%d", &n);

    while (n--) {
        int num;
        scanf("%d", &num);
        c.push_back(num);
    }

    sort(c.begin(), c.end());

    for (int i = 0; i < c.size() - 1; i++) {
        sum += c[i];
    }

    printf("%d", sum);
}
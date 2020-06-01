#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        if (N % i == 0) nums.push_back(i);
    }

    cout << nums[K - 1];

    return 0;
}
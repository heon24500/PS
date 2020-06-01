#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<float> nums;
    scanf("%d", &n);

    while (n--) {
        float num;
        scanf("%f", &num);
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    printf("%.2f", nums[1]);
}
#include <iostream>
#include <vector>
using namespace std;

#define max_N 100005

int ccnt[max_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
        ccnt[num]++;
    }

    int ret = -1;

    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (nums[i] == nums[j]) cnt++;
        }
        if (cnt == nums[i]) {
            if (ret < nums[i]) ret = nums[i];
        }
    }

    if (ccnt[0] == 0 && ret == -1) ret = 0;



    cout << ret;
}
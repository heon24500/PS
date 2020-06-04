#include <string>
#include <vector>

using namespace std;

int answer = 0;

void solve(int idx, vector<int> nums, vector<int> sum, int t) {
    if (idx == nums.size()) {
        int ret = 0;
        for (int i = 0; i < sum.size(); i++) {
            ret += sum[i];
        }
        if (ret == t) answer++;
        return;
    }

    sum.push_back(nums[idx]);
    solve(idx + 1, nums, sum, t);
    sum.pop_back();

    sum.push_back(nums[idx] * (-1));
    solve(idx + 1, nums, sum, t);
    sum.pop_back();
}

int solution(vector<int> numbers, int target) {
    vector<int> temp;
    solve(0, numbers, temp, target);
    return answer;
}
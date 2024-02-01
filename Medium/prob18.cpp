// 4Sum
// Array | Two Pointers | Sorting
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public: 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int num = nums.size();
        if (num < 4) return ans;

        for (int i = 0; i < num; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < num; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int m = j + 1;
                int n = num - 1;
                while (m < n) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[m];
                    sum += nums[n];
                    if (sum < target) m++;
                    else if (sum > target) n--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[m], nums[n]});
                        while (m < n && nums[m] == nums[m + 1]) m++;
                        while (m < n && nums[n] == nums[n - 1]) n--;
                        m++;
                        n--;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    vector<int> num = {-3, -1, 0, 2, 4, 5};
    int target = 0;
    Solution so;
    vector<vector<int>> result = so.fourSumV2(num, target);
    for (const auto &innervector : result) {
        for (const auto &element : innervector) {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}
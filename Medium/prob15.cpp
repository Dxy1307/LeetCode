// 3Sum
// Array | Two Pointers | Sorting
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            int k = n - 1;
            int target = -nums[i];
            while(j < k) {
                if (nums[j] + nums[k] < target) j++;
                else if (nums[j] + nums[k] > target) k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1]) i++;   
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    vector<int> num = {-2, 0, 0, 2, 2};
    Solution so;
    vector<vector<int>> result = so.threeSum(num);
    for (const auto &innervector : result) {
        for (const auto &element : innervector) {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}
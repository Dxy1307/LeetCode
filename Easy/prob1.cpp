// Two Sum
// Array | Hash Table
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int temp = target - nums[i];
            if (map.count(temp)) 
                return {map[temp], i};
            map[nums[i]] = i;
        }
        
        return {};
    }
};

int main() {
    ios_base::sync_with_stdio(false);;
    cin.tie(0);cout.tie(0);

    vector<int> num = {2, 7, 11, 15};
    int target = 9;
    Solution so;
    vector<int> rs = so.twoSum(num, target);
    for(const auto &element : rs) {
        cout << element << " ";
    }
    return 0;
}
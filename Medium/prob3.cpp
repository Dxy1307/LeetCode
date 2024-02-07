// Longest Substring Without Repeating Characters
// Hash Table | String | Sliding Window
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int n = s.length();
        int maxLength = 0;
        if (n == 0) return 0;
        else {
            int l = 0;
            for (int r = 0; r < n; ++r) {
                if (map.count(s[r]) == 0 || map[s[r]] < l) {
                    map[s[r]] = r;
                    maxLength = max(maxLength, r - l + 1);
                } else {
                    l = map[s[r]] + 1;
                    map[s[r]] = r;
                }
            }
        } 
        return maxLength;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    string str = "aaaaa";
    Solution so;
    cout << so.lengthOfLongestSubstring(str) << endl;

    return 0;
}
// Dxy
// Longest Palindromic Substring
// String | Dynamic Programming
#include <iostream>
#include <string>
using namespace std;

class Solution {
public: 
    string longestPalindrome(string s) {
        string ans = s.substr(0, 1);
        int n = s.length();
        for(int i = 1; i <= n - 1; ++i) {
            int r = i - 1;
            int l = i + 1;

            while(r >= 0) {
                if(s[r] == s[i]) r--;
                else break;
            }
            r++;

            while(l < n) {
                if(s[l] == s[i]) l++;
                else break;
            }
            l--;

            while (r >= 0 && l < n) {
                if(s[r] == s[l]) {
                    if(r == 0 || l == n - 1) break;
                    else {
                        r--;
                        l++;
                    }
                } else {
                    r++;
                    l--;
                    break;
                }
            }
            string temp = s.substr(r, l - r + 1);
            if(temp.length() > ans.length()) ans = temp;
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    Solution so;

    string str = "bb";

    cout << so.longestPalindrome(str) << endl;

    return 0;
}
// Dxy
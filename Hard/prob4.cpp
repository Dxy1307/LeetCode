// Median of Two Sorted Arrays
// Array | Binary Search | Divide and Conquer
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public: 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double ans;
        int temp = m + n;

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        if (temp % 2) {
            ans = nums1[(temp-1)/2] * 1.0;
        } else {
            ans = (nums1[temp/2] + nums1[temp/2 - 1]) * 1.0 / 2;
        }
        return ans; 
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    vector<int> A = {1, 5};
    vector<int> B = {1, 2, 5, 5, 6};

    Solution so;
    double res = so.findMedianSortedArrays(A, B);
    double temp = 1.0;
    cout << res << endl;
    cout << temp << endl;
    return 0;
}
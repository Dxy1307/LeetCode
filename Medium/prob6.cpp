// Zigzag Conversion
// String
// Ý tưởng là chạy từ trên xuống dưới, sau đó chạy ngược lại, biến temp để điều chỉnh việc này
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int n = s.length();
        if(numRows == 1) return s;
        vector<string> str(numRows, "");
        int k = 0, temp = -1;
        for(int i = 0; i < n; ++i) {
            if(k == 0 || k == numRows - 1) temp *= -1;
            str[k] += s[i];
            if(temp == 1) k++;
            else k--;
        }

        for(auto &item : str) {
            ans += item;
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    Solution so;

    string str = "PAYPALISHIRING";
    int numRows = 2;

    cout << so.convert(str, numRows) << endl;

    return 0;
}
// Dxy
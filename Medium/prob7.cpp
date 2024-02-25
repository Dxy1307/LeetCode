// Reverse Integer
// Math
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while(x != 0) {
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }

        if(ans > INT32_MAX || ans < INT32_MIN) return 0;

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    Solution so;
    int x = 1534236469;
    cout << so.reverse(x) << endl;

    return 0;
}
// Dxy
class Solution {
public:
    int arrangeCoins(int n) {
        long long i = 1, count = 0;
        while (n >= i) {
            n -= i;
            ++count;
            ++i;
        }
        return count;
    }
};

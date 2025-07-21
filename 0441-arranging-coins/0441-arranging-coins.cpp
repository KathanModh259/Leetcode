class Solution {
public:
    int arrangeCoins(int n) {
        
        long long nn = (long long)n;
        return (int)((sqrt(8 * nn + 1) - 1) / 2);
    }
};
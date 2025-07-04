class Solution {
public:
    bool check(string s, int left, int right) {
        int count = 0;

        while (left < right) {
            if (s[left] != s[right]) {
                count++;
                if (count == 2) return false;

                // Try skipping left or right (only once)
                return (isPurePalindrome(s, left + 1, right) || isPurePalindrome(s, left, right - 1));
            }
            left++;
            right--;
        }

        return true;
    }

    bool isPurePalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        return check(s, 0, s.length() - 1);
    }
};

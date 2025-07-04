class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;


        for (char ch : s) {
            freq[ch]++;
        }

        int count = 0;
        bool oddUsed = false;


        for (auto it : freq) {
            int charCount = it.second;


            if (charCount % 2 == 0) {
                count += charCount;
            }

            else {
                count += charCount - 1;
                oddUsed = true; 
            }
        }


        if (oddUsed) {
            count += 1;
        }

        return count;
    }
};

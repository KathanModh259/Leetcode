class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string repeated = word;
        int k = 1;
        
        while (sequence.find(repeated) != string::npos) {
            repeated += word;
            ++k;
        }
        
        return k - 1;
    }
};

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> answer(n, n); 

        int prev = -n; 
        for (int i = 0; i < n; i++) {
            if (s[i] == c) prev = i;
            answer[i] = i - prev;
        }

        prev = 2 * n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) prev = i;
            answer[i] = min(answer[i], abs(prev - i));
        }

        return answer;
    }
};

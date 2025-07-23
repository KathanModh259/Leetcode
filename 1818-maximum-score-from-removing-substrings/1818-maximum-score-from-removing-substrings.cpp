class Solution {
public:
    int maximumGain(string s, int x, int y) {

        if (x < y) {
            swap(x, y);

            for (char &c : s) {
                if (c == 'a') c = 'b';
                else if (c == 'b') c = 'a';
            }
        }

        int total = 0;
        stack<char> st;


        string temp;
        for (char c : s) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                total += x;
            } else {
                st.push(c);
            }
        }

        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }

        reverse(temp.begin(), temp.end());
        for (char c : temp) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                total += y;
            } else {
                st.push(c);
            }
        }

        return total;
    }
};

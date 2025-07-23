class Solution {
public:

    char nextChar(char ch) {
        return (ch == 'z') ? 'a' : ch + 1;
    }


    string transform(const string& s) {
        string result = "";
        for (char ch : s) {
            result += nextChar(ch);
        }
        return result;
    }

    char kthCharacter(int k) {
        string word = "a";
        while (word.length() < k) {
            word += transform(word);
        }
        return word[k - 1];
    }
};

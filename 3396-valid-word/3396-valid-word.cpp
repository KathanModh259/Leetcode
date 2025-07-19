class Solution {
public:
    bool isValid(string word) {  
        if (word.length() < 3) return false;

        int asciiSum = 0;
        bool hasVowel = false, hasConsonant = false;

        for (char ch : word) {
            if (!isalnum(ch)) return false; 

            if (isalpha(ch)) {
                asciiSum += ch;

                char lower = tolower(ch);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                    hasVowel = true;
                else
                    hasConsonant = true;
            }
        }

        return hasVowel && hasConsonant;
    }
};

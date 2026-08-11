class Solution:
    def minTimeToType(self, word: str) -> int:
        ans = len(word)
        curr_ptr = 1

        for c in word :
            pos = ord(c)-96
            diff = abs(pos - curr_ptr)
            ans += min(diff,26-diff)
            curr_ptr = pos
        return ans    
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int left = 0, curr_sum = 0, max_sum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (freq.count(nums[right])) {
                freq.erase(nums[left]);
                curr_sum -= nums[left];
                ++left;
            }
            freq[nums[right]] = 1;
            curr_sum += nums[right];
            max_sum = max(max_sum, curr_sum);
        }

        return max_sum;
    }
};


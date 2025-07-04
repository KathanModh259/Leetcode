class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);  
        int i = 0;              
        int j = n - 1;          

        for (int k = 0; k < n; ++k) {
            if (nums[k] % 2 == 0) {
                result[i++] = nums[k]; 
            } else {
                result[j--] = nums[k];  
            }
        }

        return result;
    }
};

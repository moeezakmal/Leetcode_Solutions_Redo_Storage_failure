class Solution {
public:
    
    // Time: O(n^2)
    // Space: O(n), if result vector not considered then O(1)
    
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(), 1);

        for (int i=nums.size(); i>=0; i--)
        {
           for(int j = i+1; j < nums.size(); j++)
           {
                if (nums[j] > nums[i]) // important check to make sure sequence is indeed increasing
                {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
           } 
        }

        return *max_element(LIS.begin(), LIS.end());

    }
};
class Solution {
public:
    
    // Time: O(n^2)
    // Space: O(logn)
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //O(nlogn)
        vector<vector<int>> res; 

        for (int i=0; i<nums.size(); i++) // O(n)
        {
            if (i > 0 && nums[i] == nums[i-1])
                continue; 
            
            int l = i+1, r = nums.size()-1;

            while (l < r) // O(n)
            {
                if ((nums[l] + nums[r] + nums[i]) == 0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l-1] && l<r) // O(1)
                        l++;
                    continue;
                }

                if ((nums[l] + nums[r] + nums[i]) > 0) r--;
                else l++;

            }
        
        }
        
        return res;
    }
};
class Solution {
public:
    
    // Time: O(log n)
    // Space: O(1)
    
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int min_val = INT_MAX;
        
        while (l <= r)
        {   
            // avoids unnecessary iterations
            if (nums[l] < nums[r]){
                 min_val = min(min_val, nums[l]);
                 break;
            }
            
            
            min_val = min(min_val, nums[(l+r)/2]);
            
            if (nums[(l+r)/2] > nums[r])
                l = ((l+r)/2) + 1;

            else
                r = ((l+r)/2) - 1;
        }

        return min_val;
    }
};
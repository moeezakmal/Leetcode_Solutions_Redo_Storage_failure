class Solution {
public:
    
    // Time: O(log n)
    // Space: O(1)
    
    
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while (l <= r)
        {   
            if (nums[(l+r)/2] == target)
                return (l+r)/2;
            
            
            // left
            if (nums[(l+r)/2] > nums[r]){
                if (target > nums[(l+r)/2] || target < nums[l])
                    l = ((l+r)/2) + 1;
                else
                    r = ((l+r)/2) - 1;
            }

            
            // right
            else{
                if (target < nums[(l+r)/2] || target > nums[r])
                    r = ((l+r)/2) - 1;
                else
                    l = ((l+r)/2) + 1;
                // if (target >= nums[(l+r)/2] && target <= nums[r]) // Applying De Morgan's law to !(A || B) gives !A && !B.
                //     l = ((l+r)/2) + 1;
                // else
                //     r = ((l+r)/2) - 1;
            }
        }

        return -1;
    }
};
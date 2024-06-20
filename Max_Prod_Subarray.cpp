class Solution {
public:
    // int maxProduct(vector<int>& nums) {
    //     long long prod = *max_element(nums.begin(), nums.end());
    //     long long curr_min = 1, curr_max = 1;

    //     for (int i=0; i<nums.size(); i++)
    //     {   
    //         long long temp = curr_max * nums[i];
    //         curr_max = max(nums[i] * curr_max, nums[i] * curr_min);
    //         curr_max = max(curr_max, (long long)nums[i]);
    //         curr_min = min(temp, nums[i] * curr_min);
    //         curr_min = min(curr_min, (long long)nums[i]);
    //         prod = max(prod, curr_max);
    //     }

    //     return (int)prod;
    // }



    // for both approaches
    // Time: O(n)
    // Space: O(1)


    int maxProduct(vector<int>& nums) {
        long long prod = *max_element(nums.begin(), nums.end());
        long long curr_min = 1, curr_max = 1;

        for (int i=0; i<nums.size(); i++)
        {   
            if (nums[i] < 0)
                swap(curr_max, curr_min);
            
            curr_max = max(nums[i] * curr_max, (long long)nums[i]);
            curr_min = min(nums[i] * curr_min, (long long)nums[i]);
            
            prod = max(prod, curr_max);
        }

        return (int)prod;
    }
};
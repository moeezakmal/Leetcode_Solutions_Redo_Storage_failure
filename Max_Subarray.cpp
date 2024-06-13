class Solution {
public:
    
    // Time: O(n)
    // Space: O(1)
    
    int maxSubArray(vector<int>& nums) {
        // int curr_sum = nums[0];
        int curr_sum = 0;
        int sum = numeric_limits<int>::min();

        for (int r=0; r<nums.size(); r++)
        {
            if (curr_sum < 0)
            {   
                curr_sum = nums[r];
            }
            else
            {
                curr_sum += nums[r];
                // cout << "curr_sum:" << curr_sum << endl;
                // cout << sum;
            }

            sum = max(sum, curr_sum);
        }

        return sum;
    }




    // // Cleaner approach
    
    // // Time: O(n)
    // // Space: O(1)


    // int maxSubArray(vector<int>& nums) {
    //     int curr_sum = nums[0];
    //     int sum = curr_sum;

    //     for (int r=1; r<nums.size(); r++)
    //     {
    //         curr_sum = max(nums[r], curr_sum + nums[r]);
    //         sum = max(sum, curr_sum);
    //     }

    //     return sum;
    // }

};
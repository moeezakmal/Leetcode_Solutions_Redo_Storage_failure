class Solution {
public:
    
    // //Time: O(n)
    // //Space: O(1)
    
    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int res = 0;

    //     for (int i=1; i<=n; i++)
    //     {
    //         res = res^i;
    //     }

    //     for (int i=0; i<nums.size(); i++)
    //     {
    //         res = res^nums[i];
    //     }

    //     return res;
    // }



    //Time: O(n)
    //Space: O(1)
    
    int missingNumber(vector<int>& nums) {
        int res = nums.size();

        // cout << res;

        for (int i=0; i<nums.size(); i++)
        {
            res += (i - nums[i]);
        }

        return res;
    }
};
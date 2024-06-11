class Solution {
public:
    
    // Time: O(n)
    // Space: O(1) -> output array doesn't count
    
    
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        
        output.push_back(1); 
        for(int i=0; i<nums.size()-1; i++)  //O(n)
        {
            output.push_back(nums[i] * output[i]);
        }

        // int pre_mul = 1; 
        // for(int i=0; i<nums.size(); i++)
        // {
        //     output.push_back(pre_mul);
        //     pre_mul *= nums[i];
        // }

        int mul = 1;
        for(int i=nums.size()-1; i>=0; i--) //O(n)
        {
            output[i] = output[i] * mul;
            // mul = mul * nums[i];
            mul *= nums[i];
        }

        return output;
    }
};
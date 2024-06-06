class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for (int i=0; i<nums.size(); i++)
    //     {
    //         for(int j=i+1; j<nums.size(); j++)
    //         {
    //             if (nums[i] + nums[j] == target)
    //                 return {i,j};

    //         }
    //     }
    //     return{NULL, NULL};
    // }

    
    // Time: O(n)
    // Memory: O(n)
    
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for (int i=0; i<nums.size(); i++) //O(n)
        {
            if (umap.find(target - nums[i]) != umap.end()) //O(1)
            {
                return {i, umap[target - nums[i]]};
            }
            umap[nums[i]] = i; //O(1)
        }

        return {};
    }
};
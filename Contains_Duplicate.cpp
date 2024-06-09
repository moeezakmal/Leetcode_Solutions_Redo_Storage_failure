class Solution {
public:
    
    /*--------------------------------------------------------*/

    // // Time: O(n*log(n))
    // // Space: O(n)
    
    
    // bool containsDuplicate(vector<int>& nums) {
    //     set<int> s;

    //     for(int i=0; i<nums.size(); i++) // O(n)
    //     {
    //         if(s.find(nums[i]) == s.end())  // O(log(n))   //binary search at back-end(Red-Black tree)
    //             s.insert(nums[i]);  // O(log(n)) 
    //         else
    //         {
    //             // cout << nums[i];
    //             // cout << "position:" << distance(s.begin(), s.find(nums[i]));
    //             return true;
    //         }
    //     }

    //     return false;
    // }

    /*--------------------------------------------------------*/


    // Time: O(n)
    // Space: O(n)
    
    
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;

        for(int i=0; i<nums.size(); i++) // O(n)
                umap[nums[i]]++;  // O(1) 
        
        for (auto i : umap)
        {    
            if (i.second >= 2)
                return true;
        }

        return false;
    }

};
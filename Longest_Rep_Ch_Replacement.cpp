class Solution {
public:

    // // Time: O(26.n) -> 26 char in hashmap, when searching for max
    // // Space: O(1) [O(26)]  -> hashmap space
    
    // int characterReplacement(string s, int k) {
    //     int l = 0, res = 0;
    //     unordered_map<char, int> umap;

    //     for(int r=0; r<s.size(); r++)
    //     {
    //         umap[s[r]]++;
            
    //         int max_freq = INT_MIN;
            
    //         for (const auto& pair : umap) {
    //             max_freq = max(max_freq, pair.second);
    //         }
            
    //         while (((r-l+1)-max_freq) > k)
    //         {
    //             umap[s[l]]--;
    //             l++;
    //         }
            
    //         res = max(res, r-l+1);
    //     }

    //     return res;
    // }
    
    
    
    // Time: O(n)
    // Space: O(1) [O(26)] -> hashmap space

    int characterReplacement(string s, int k) {
        int l = 0, res = 0;
        unordered_map<char, int> umap;
        
        int maxf = 0;

        for(int r=0; r<s.size(); r++)
        {
            umap[s[r]]++;
            maxf = max(maxf, umap[s[r]]);
            
            while (((r-l+1)-maxf) > k)
            {
                umap[s[l]]--;
                l++;
            }
            
            res = max(res, r-l+1);
        }

        return res;
    }
};
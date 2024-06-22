class Solution {
public:
    
    // // Time: O(n)
    // // Space: O(n)
    
    // vector<int> countBits(int n) {
    //     vector<int> res;
        
    //     for (int i=0;i<=n;i++) //O(n)
    //     {
    //         int nbits = 0;
    //         int temp = i;
    //         while (temp!=0) //O(1)
    //         {
    //             nbits+=temp&1;
    //             temp=temp>>1;
    //         }

    //         res.push_back(nbits);
    //     }

    //     return res;
    // }



    // Dynammic Programming
    // Time: O(n)
    // Space: O(n)
    
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        int offset = 1;
        
        for (int i=1;i<=n;i++) //O(n)
        {
            if (offset*2 == i)
                offset = i;

            dp[i] = 1 + dp[i-offset];
        }

        return dp;
    }
};
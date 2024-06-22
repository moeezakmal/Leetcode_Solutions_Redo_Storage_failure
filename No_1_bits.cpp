class Solution {
public:
    
    // // Time: O(1) -> 32 bit (int)
    // // Space: O(1)
    
    // int hammingWeight(int n) {
    //     int nbits = 0;
    //     while (n!=0)
    //     {
    //         nbits+=n&1;
    //         n=n>>1;
    //     }

    //     return nbits;
    // }


    // 2nd solution
    // Time: O(1) -> 32 bit (int)
    // Space: O(1)
    
    int hammingWeight(int n) {
        int nbits = 0;
        while (n!=0)
        {
            n=n&(n-1);
            nbits++;
        }

        return nbits;
    }
};
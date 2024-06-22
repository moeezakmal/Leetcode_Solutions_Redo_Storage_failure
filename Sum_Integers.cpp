class Solution {
public:
    
    // Time: O(1)  -> worst O(n) (based on number of levels)
    // Space: O(1)
    
    
    int getSum(int a, int b) {
        
        while(b!=0)
        {
            int temp = a;
            a = a^b;
            b = (temp&b)<<1;
        }

        return a;
    }
};
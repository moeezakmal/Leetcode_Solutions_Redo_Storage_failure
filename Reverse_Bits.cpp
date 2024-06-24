class Solution {
public:
    
    // Time: O(1)
    // Space: O(1)

    uint32_t reverseBits(uint32_t n) {
        int res = 0;

        for (int i=0; i<32; i++)  // O(1)
        {
            int bit = (n>>i) & 1;
            res |= (bit << (31-i));
        }

        return res;
    }
};
class Solution {
public:
    
    // Time: O(n)
    // Space: O(1)
    
    
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int maxA = 0; 

        while(l<r)
        {
            if(height[l]<=height[r])
            {
                maxA = max(maxA,height[l]*(r-l));
                l++;
            }
            else
            {
                maxA = max(maxA,height[r]*(r-l));
                r--;
            }
        }

        return maxA;
    }
};
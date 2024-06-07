class Solution {
public:
    
    // Time: O(n)
    // Space/Memory: O(1)
    
    int maxProfit(vector<int>& prices) {
        int l=0, diff=0;

        for (int r = 1; r < prices.size(); r++)
        {
            if (prices[l] < prices[r])
            {
                // cout << "r:" << r << " ";
                // cout << "l:" << l << " ";
                if((prices[r] - prices[l]) > diff)
                    diff = prices[r] - prices[l];
                // diff = max(prices[r] - prices[l], diff);
            }

            else
            {
                l=r;
            }
        }

        return diff;
    }
};
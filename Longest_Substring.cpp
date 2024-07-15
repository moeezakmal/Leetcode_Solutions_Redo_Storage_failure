// Time: O(n)
// Space: O(n) -> max set size


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> s1;

        int l = 0, res =0;
        
        for(int r=0; r<s.size(); r++)
        {
            while(s1.find(s[r]) != s1.end()) // distance(s.begin(), s.find(x))
            {
                s1.erase(s[l]);
                l++;
            }
            s1.insert(s[r]);
            res = max(res, r-l+1);
        }
        return res;
    }
};
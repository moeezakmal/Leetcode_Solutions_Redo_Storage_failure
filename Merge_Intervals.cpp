// Time: O(nlogn) -> because of sorting
// Memory: O(1) -> output doesn't count

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> res = {intervals[0]};

        for (int i = 1; i < intervals.size(); ++i) {
            int Lastend = res.back()[1];
            
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start <= Lastend)
                res.back()[1] = max(Lastend, end);
            else
                res.push_back({start, end});
        }

        return res;
    }
};
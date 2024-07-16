// Time: O(n) -> traverse through string
// Space: O(n) -> stack size


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> umap;

        umap.insert({')', '('});
        umap.insert({'}', '{'});
        umap.insert({']', '['});

        for(int i=0; i<s.size(); i++)
        {
            if(umap.find(s[i]) != umap.end())
            {
                if(!stk.empty() && stk.top() == umap[s[i]])
                {
                    stk.pop();
                    continue;
                }
            }

            stk.push(s[i]);
        }

        if(stk.empty())
            return true;
        return false;
    }
};
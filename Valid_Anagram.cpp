// Time: O(n)
// Space: O(n) -> hashmap


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        unordered_map<char, int> umap;

        for (int i=0; i<s.size(); i++)
        {
            umap[s[i]]++;
        }

        for (int j=0; j<t.size(); j++)
        {
            umap[t[j]]--;
        }

        for (const auto& traverse : umap) 
        {
            if (traverse.second != 0)
                return false;    
        }

        return true;
    }
};
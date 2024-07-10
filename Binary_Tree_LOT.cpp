// Time: O(n)  -> visits each node once
// Memory: O(n) -> biggest level possible n/2

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(root == NULL) 
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int qLen = q.size();
            vector<int> level;

            for(int i=0; i<qLen; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if (node)
                {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (!level.empty())
                res.push_back(level);
        }
        return res;
    }
};
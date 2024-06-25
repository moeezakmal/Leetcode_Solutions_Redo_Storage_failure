class Solution {
public:
    
    // Time: O(n) -> each node visited once
    // Space: O(h) -> worst case: O(n) if tree is not balanced, best case: O(logn) if tree is balanced

    
    int maxPathSum(TreeNode* root) {
       int res = root->val;

       dfs(root, res);
       return res;
    }


    int dfs(TreeNode* root, int& res)
    {
        if (root == NULL)
            return 0;

        // dealing with negative values -> max(val, 0)
        int leftMax = max(dfs(root->left, res), 0);
        int rightMax = max(dfs(root->right, res), 0);

        res = max(res, root->val + leftMax + rightMax); // max value encountered

        return root->val + max(leftMax, rightMax); // return value for current node
    }
};
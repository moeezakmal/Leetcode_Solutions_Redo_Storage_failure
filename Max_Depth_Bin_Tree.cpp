class Solution {
public:
    
    // Time: O(n)
    // Space: O(1)
    
    int maxDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        
        return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
        // return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};
class Solution {
public:
    
    // Time: O(n) -> Tree Depth
    // Space: O(n) -> stack for recursion
    
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL)
            return NULL;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
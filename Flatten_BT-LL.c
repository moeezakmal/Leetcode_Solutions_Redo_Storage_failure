// Time: O(n)
// Space: O(h) -> height of the recursion stack

struct TreeNode* flattenTree(struct TreeNode* node) {
    if (!node)
        return NULL;

    if (!node->left && !node->right)
        return node;
    
    struct TreeNode* leftTail = flattenTree(node->left);
    struct TreeNode* rightTail = flattenTree(node->right);
    
    if (leftTail) {
        leftTail->right = node->right;
        node->right = node->left;
        node->left = NULL;
    }
    
    return rightTail ? rightTail : leftTail;
}
void flatten(struct TreeNode* root) { flattenTree(root); }
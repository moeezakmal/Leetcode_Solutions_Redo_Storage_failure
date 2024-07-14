// Time: O(n*m) -> in the most unfavorable situation, for each of the n nodes in the main tree, 
//                 one might need to traverse up to m nodes in the subtree
// Space: O(h) -> height of root tree => O(n) in worst case if tree is skewed


class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == NULL)
            return true;
        
        if (root == NULL && subRoot != NULL)
            return false;

        if (isSameTree(root, subRoot))
            return true;

        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }


    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if (p == NULL && q == NULL)
            return true;
        
        if (p && q && p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        return false;
    }
};
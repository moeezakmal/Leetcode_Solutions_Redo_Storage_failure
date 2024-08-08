/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


// Time: O(n)
// Space: O(n)

// void inorder(struct TreeNode* root, int* res, int* idx) {
//     if (root != NULL) {
//         inorder(root->left, res, idx);
//         res[(*idx)++] = root->val;
//         inorder(root->right, res, idx);
//     }
// }

// int* inorderTraversal(struct TreeNode* root, int* returnSize) {
//     int* res = (int*)malloc(100 * sizeof(int));
//     *returnSize = 0;
//     inorder(root, res, returnSize);
//     return res;
// }


// Time: O(n)
// Space: O(n)

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    struct TreeNode* stack[100];
    int top = -1;

    while(root || top>-1)
    {
        while(root != NULL)
        {
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        res[(*returnSize)++] = root->val;
        root = root->right;
    }
    return res;
}
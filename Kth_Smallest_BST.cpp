// Time: O(n) -> all nodes could be visited
// Space: O(n) -> stack size


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int n=0;

        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while (curr || !stk.empty())
        {
            while (curr)
            {
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            stk.pop();
            n++;
            
            if (n==k)
                return curr->val;
            
            curr = curr->right;
        }

        return -1;
    }
};
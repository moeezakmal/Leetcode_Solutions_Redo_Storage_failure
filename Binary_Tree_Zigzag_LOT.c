// Time: O(n)
// Space: O(n)


void reverseArr(int* arr, int length) {
    int l=0, r=length-1;
    while (l<r)
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}


int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int));

    if (root == NULL)
        return res;

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front != rear)
    {
        int qLen = rear - front;
        int* level = (int*)malloc(sizeof(int)*qLen);
        int levelCount = 0;
        *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));
        (*returnColumnSizes)[*returnSize] = qLen;

        for(int i=0; i<qLen; i++)
        {
            struct TreeNode* node = queue[front++];
            
            level[levelCount++] = node->val;
            if (node->left != NULL) queue[rear++] = node->left;
            if (node->right != NULL) queue[rear++] = node->right;
        }
        if (levelCount > 0) {
            if (*returnSize % 2 == 1)
                reverseArr(level, levelCount);
            res = realloc(res, sizeof(int*)*(*returnSize+1));
            res[(*returnSize)++] = level;
        }
    }
    return res;
}
// Time: O(nlogn)
// Space: O(n)


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b) {
    const int *ia = *(const int **)a;
    const int *ib = *(const int **)b;
    return ia[0] - ib[0];
}


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** res = (int**)malloc(intervalsSize * sizeof(int*));
    int resSize = 0;
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    
    
    res[0] = (int*)malloc(2 * sizeof(int));
    res[0][0] = intervals[0][0];
    res[0][1] = intervals[0][1];
    resSize++;
    
    for (int i = 1; i < intervalsSize; ++i) {
        int lastEnd = res[resSize - 1][1];
        int start = intervals[i][0];
        int end = intervals[i][1];
        
        if (start <= lastEnd) {
            
            res[resSize - 1][1] = (end > lastEnd) ? end : lastEnd;
        } else {
            
            res[resSize] = (int*)malloc(2 * sizeof(int));
            res[resSize][0] = start;
            res[resSize][1] = end;
            resSize++;
        }
    }

    
    *returnSize = resSize;
    for (int i = 0; i < resSize; ++i) {
        (*returnColumnSizes)[i] = 2;
    } 

    return res;
}
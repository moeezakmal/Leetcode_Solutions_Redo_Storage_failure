// Time: O(n)
// Space: O(1)


int removeDuplicates(int* nums, int numsSize) {
    // printf("%d", numsSize);

    if (numsSize == 0 || numsSize == 1)
        return numsSize;

    int l = 1;
    for (size_t r=1; r<numsSize; r++)
    {
        if (nums[r-1] == nums[r])
            continue;
        else {
            nums[l] = nums[r];
            l++;
        }
    }
    return l;
}
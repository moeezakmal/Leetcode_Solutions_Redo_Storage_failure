// // Time: O(n)
// // Space: O(n)

// void rotate(int* nums, int numsSize, int k) {
//     int* arr = (int*)malloc(sizeof(int)*numsSize);
    
//     for (int i = 0; i < numsSize; i++) {
//             arr[(i+k)%numsSize] = nums[i];
//         }
    
//     for (int i = 0; i < numsSize; i++) {
//         nums[i] = arr[i];
//     }
// }


// Time: O(n)
// Space: O(1)

void reverseArr(int* arr, int l, int r) {
    while (l<r)
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;

    reverseArr(nums, 0, numsSize-1);
    reverseArr(nums, 0, k-1);
    reverseArr(nums, k, numsSize-1);

}
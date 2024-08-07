// Time: O(m+n)
// Space: O(1)

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    for (int r=nums1Size-1; r>=0; r--)
    {
        if ((m>0 && n>0 && nums1[m-1] > nums2[n-1]) || (n==0 && m>0))
        {   
            nums1[r] = nums1[m-1];
            m--;
        }
        else if ((m>0 && n>0 && nums1[m-1] <= nums2[n-1]) || (m==0 && n>0))
        {   
            nums1[r] = nums2[n-1];
            n--;
        }
    }
}
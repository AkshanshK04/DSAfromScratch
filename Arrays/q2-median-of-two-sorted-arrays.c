double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0, k = 0;
    int n = nums1Size + nums2Size;
    int merged[n];
    while ( i <nums1Size && j < nums2Size)
    {
        if ( nums1[i] < nums2[j] )
            merged[k++] = nums1[i++];
        else
            merged[k++] = nums2[j++];
    }

    while(i < nums1Size)
        merged[k++] = nums1[i++];
    while(j < nums2Size)
        merged[k++] = nums2[j++];
    
    if(n % 2 == 0)
    {
        return (merged[n/2 - 1] + merged[n/2]) / 2.0;
    }
    else
    {
        return merged[n/2];
    }
}
int searchInsert(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize-1;
    int f=-1;
    while ( l <= r)
    {
        int m = l + (r-l)/2;
        if ( nums[m] == target)
        {
            f=1;
            return m;
        }
        else if ( nums[m]< target)
            l=m+1;
        else
            r=m-1;
        
    }

    return l;
}
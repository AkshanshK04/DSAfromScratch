/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int l = 0, r = numsSize-1;
    int f=-1,s=-1;
    while ( l <= r)
    {
        int m = l + (r-l)/2;
        if ( nums[m] == target)
        {
            f = m;
            r = m-1;
        }
        else if ( nums[m]< target)
            l=m+1;
        else
            r=m-1;
        
    }

    l = 0, r = numsSize-1;

    while ( l <= r)
    {
        int m = l + (r-l)/2;
        if ( nums[m] == target)
        {
            s = m;
            l = m+1;
        }
        else if ( nums[m]< target)
            l=m+1;
        else
            r=m-1;
        
    }
    *returnSize = 2;
    int* ans = malloc(2*sizeof(int));
    ans[0] = f;
    ans[1] = s;
    return ans;
   
}
int compare( const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

bool search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize-1;
    qsort(nums, numsSize, sizeof(int), compare);
    while ( l<= r)
    {
        int mid = (l + r)/2;
        if ( nums[mid] == target)
            return true;
        else if ( nums[mid] < target)
            l = mid+1;
        else
            r = mid-1;
    }    

    return false;
}
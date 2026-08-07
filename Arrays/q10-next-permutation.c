void nextPermutation(int* nums, int numsSize) {
    int pivot = -1;
    int j = numsSize - 1;
    while ( j> 0 )
    {
        if (nums[j-1] < nums[j])
        {
            pivot = j-1;
            break;
        }
        j--;
    }
    if (pivot != -1)
    { 
        j = numsSize - 1;
        while ( nums[j]<=nums[pivot])
            j--;
        
        int temp = nums[pivot];
        nums[pivot] = nums[j];
        nums[j] = temp;
    }

    
    int left = pivot+1;
    int k = numsSize-1;
    while (left <k)
    {
        int swap = nums[left];
        nums[left] = nums[k];
        nums[k] = swap;
        left++;
        k--;
    } 
        
}
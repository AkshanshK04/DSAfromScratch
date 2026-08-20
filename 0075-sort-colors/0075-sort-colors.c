void sortColors(int* nums, int numsSize) {
    for ( int i = 0; i<numsSize; i++)
    {
        for ( int j = 1; j<numsSize; j++)
        {
            if ( nums[j] < nums[j-1])
            {
                int temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
            }
        }
    }   
}
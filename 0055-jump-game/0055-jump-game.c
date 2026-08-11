bool canJump(int* nums, int numsSize) {
    int far = 0;
    for ( int i=0; i<numsSize; i++)
    {
        if ( i>far)
            return false;
        if ( i+nums[i] >= far)
            far = i+nums[i];
        
    }
    
    return true;
}
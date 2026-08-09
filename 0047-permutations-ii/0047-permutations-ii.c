/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

void backtrack (int* nums,int numsSize, int* current, int currentSize, int* used, int** result, int* returnSize, int** returnColumnSizes){

    if ( currentSize == numsSize)
    {
        result[*returnSize] = malloc(numsSize*sizeof(int));
        for ( int i =0; i<numsSize; i++)
            result[*returnSize][i] = current[i];
        
        (*returnColumnSizes)[*returnSize] =  numsSize;
        (*returnSize)++;
        return;
    }

    for ( int i=0; i<numsSize; i++)
    {
        if (used[i])
            continue;
        
        if (i> 0 && nums[i] == nums[i-1] && !used[i-1])
            continue;

        used[i]= 1;
        current[currentSize] = nums[i];
        backtrack(nums, numsSize, current, currentSize +1, used, result, returnSize, returnColumnSizes);
        used[i] = 0;
    }
}


int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums,numsSize, sizeof(int), compare);
    *returnSize = 0;
    int all =1;

    for (int i=1; i<= numsSize; i++)
        all*=i;
    
    int** result = malloc(all*sizeof(int*));
    *returnColumnSizes = malloc(all*sizeof(int));
    int* current = malloc(numsSize*sizeof(int));
    int* used = calloc(numsSize, sizeof(int));

    backtrack(nums, numsSize, current, 0, used, result, returnSize, returnColumnSizes);
    free(current);
    free(used);

    return result;
}
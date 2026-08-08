/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 void backtrack ( int* candidates , int candidatesSize, int target, int start, int* temp, int tempSize, int*** ans, int* returnSize, int** returnColumnSizes, int* capacity)
 {
    if ( target==0)
    {
        if ( *returnSize == *capacity)
        {
            *capacity*=2;
            *ans = realloc(*ans, *capacity*sizeof(int*));
            *returnColumnSizes = realloc(*returnColumnSizes, *capacity*sizeof(int));
        }

         (*ans)[*returnSize] = malloc(tempSize*sizeof(int));

        for ( int i=0; i<tempSize; i++)
        {
            (*ans)[*returnSize][i] = temp[i];
        }

        (*returnColumnSizes)[*returnSize] = tempSize;
        (*returnSize)++;

        return;
    }

    for ( int i=start; i<candidatesSize; i++)
    {
        if (candidates[i] > target)
            continue;
        
        temp[tempSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i,temp, tempSize+1, ans, returnSize, returnColumnSizes, capacity);
    }

 }
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int capacity = 100;
    int** ans = malloc(capacity*sizeof(int*));
    *returnColumnSizes = malloc(capacity*sizeof(int));
    *returnSize = 0;
    int *temp = malloc(target*sizeof(int));
    backtrack (candidates, candidatesSize,target,0, temp,0,&ans, returnSize, returnColumnSizes, &capacity);
    free(temp);
    return ans;
}
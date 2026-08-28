/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare ( const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort( nums , numsSize, sizeof(int), compare);
    int total = 1 << numsSize;

    int** res = malloc( total * sizeof(int*));
    *returnColumnSizes = malloc(total * sizeof(int));

    int* path = malloc( numsSize * sizeof(int));
    *returnSize = 0;

    int* start = malloc( total * sizeof(int));
    int* size = malloc( total * sizeof(int));
    int* idx = malloc( total * sizeof(int));

    int top = 0;
    start[0] = 0;
    size[0] = 0;
    idx[0] = 0;

    res[*returnSize] = malloc(0);
    (*returnColumnSizes)[*returnSize] = 0;
    (*returnSize)++;

    while ( top >= 0)
    {
        int s= start[top];
        int sz = size[top];
        int i = idx[top];

        if ( i>= numsSize)
        {
            top--;
            continue;
        }

        idx[top]++;

        if ( i>s && nums[i] == nums[i-1])
            continue;
        
        path[sz] = nums[i];

        res[*returnSize] = malloc((sz+1)*sizeof(int));

        for ( int j =0; j<= sz; j++)
            res[*returnSize][j] = path[j];
        
        (*returnColumnSizes)[*returnSize] = sz+1;
        (*returnSize)++;

        top++;
        start[top] = i+1;
        size[top] = sz+1;
        idx[top] = i+1;

    }

    free(path);
    free(start);
    free(size);
    free(idx);

    return res;
}
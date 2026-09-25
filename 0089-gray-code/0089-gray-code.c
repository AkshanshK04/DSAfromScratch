/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int size = 1<<n;

    int* res = malloc(size*sizeof(int));

    for ( int i=0; i<size; i++)
        res[i] = i^(i>>1);

    *returnSize = size;
    return res;
}
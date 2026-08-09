/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b)
{
    return (*(char*)a - *(char*)b);
}
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    char*** res = malloc(strsSize*sizeof(char**));
    *returnColumnSizes = calloc(strsSize, sizeof(int));
    char** keys = malloc(strsSize*sizeof(char*));

    for (int i =0; i<strsSize; i++)
    {
        int len = strlen(strs[i]);
        char* key = malloc((len+1)*sizeof(char));
        strcpy(key,strs[i]);
        qsort(key, len, sizeof(char), compare);
    
        int group = -1;
        for (int j = 0; j<*returnSize; j++)
        {
            if (strcmp(keys[j] , key) == 0)
            {
                group =j;
                break;
            }
        }

        if ( group == -1)
        {
            group = *returnSize;
            keys[group] = key;
            res[group] = malloc(strsSize*sizeof(char*));
            (*returnSize)++;
        }

        else 
            free(key);

        int posi = (*returnColumnSizes)[group];
        res[group][posi] = malloc((len+1)*sizeof(char));
        strcpy(res[group][posi], strs[i]);
        (*returnColumnSizes)[group]++;
    
    }

    for (int i = 0; i < *returnSize; i++)
        free(keys[i]);

    free(keys);

    return res;

}
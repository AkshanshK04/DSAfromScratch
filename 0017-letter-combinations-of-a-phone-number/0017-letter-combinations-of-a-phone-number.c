/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void backtrack (int pos, int n, char* digits, char* curr, char** res, int* returnSize, char** map)
{
    if ( pos == n)
    {
        curr[n] = '\0';
        res[*returnSize] = malloc((n+1)*sizeof(char));
        strcpy(res[*returnSize], curr);
        (*returnSize)++;
        return ;
    }

    char* l = map[digits[pos] - '0'];
    for (int i=0; l[i] != '\0'; i++)
    {
        curr[pos] = l[i];
        backtrack(pos+1, n, digits, curr, res, returnSize, map);
    }
}
char** letterCombinations(char* digits, int* returnSize) {
    if (digits == NULL || digits[0] == '\0')
    {
        *returnSize = 0;
        return NULL;
    }

    char* map[] = {
        "", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    int n = strlen(digits);
    int total = 1;
    for ( int i = 0; i<n; i++)
        total *= strlen(map[digits[i] - '0']);

    char** res = malloc(total*sizeof(char*));
    char* curr = malloc((n+1)*sizeof(char));

    *returnSize = 0;

    backtrack(0,n, digits, curr, res, returnSize, map);
    free(curr);
    return res;
}

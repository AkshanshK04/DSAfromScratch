/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char** res, int* count, char* curr,
               int pos, int o, int c, int n) {
    if (pos == 2 * n) {
        curr[pos] = '\0';
        res[*count] = malloc((2 * n + 1) * sizeof(char));
        strcpy(res[*count], curr);
        (*count)++;
        return;
    }

    if (o < n) {
        curr[pos] = '(';
        backtrack(res, count, curr, pos + 1, o + 1, c, n);
    }

    if (c < o) {
        curr[pos] = ')';
        backtrack(res, count, curr, pos + 1, o, c + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int capacity = 1;
    for (int i = 0; i < n; i++)
        capacity *= 4;

    char** res = malloc(capacity * sizeof(char*));
    char* curr = malloc((2 * n + 1) * sizeof(char));

    *returnSize = 0;

    backtrack(res, returnSize, curr, 0, 0, 0, n);

    free(curr);
    return res;

}
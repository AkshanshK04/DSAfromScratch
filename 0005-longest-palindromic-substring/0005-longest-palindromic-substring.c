char* longestPalindrome(char* s) {
     int n = strlen(s);

    if (n <= 1)
        return s;

    int start = 0;
    int maxLen = 1;

    char *dp = calloc(n, sizeof(char));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n-1; j >= i; j--) {

            if (s[i] == s[j] &&
                (j - i <= 2 || dp[j - 1])) {

                dp[j] = 1;

                if (j - i + 1 > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
            else {
                dp[j] = 0;
            }
        }
    }

    char *res = malloc(maxLen + 1);
    memcpy(res, s + start, maxLen);
    res[maxLen] = '\0';
    free(dp);
    return res;
}
bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);

    bool** dp = malloc((m+1)*sizeof(bool*));
    for ( int i=0; i<=m ; i++)
        dp[i] = calloc(n+1, sizeof(bool));
    
    dp[m][n] = true;

    for ( int j =n-2; j>=0; j--)
    {
        if (p[j+1] == '*')
            dp[m][j] = dp[m][j+2];
    }

    for ( int i = m-1; i>=0; i--)
    {
        for (int j= n-1; j>=0; j--)
        {
            bool first = (s[i] == p[j] || p[j] == '.');

            if ( j+1 <n && p[j+1] == '*')
                dp[i][j] = dp[i][j+2] || (first && dp[i+1][j]);
            else
                dp[i][j] = first && dp[i+1][j+1];
        }
    }

    bool ans = dp[0][0];
    for ( int i=0; i<=m ; i++)
        free(dp[i]);
    free(dp);
    return ans;
}
char* multiply(char* num1, char* num2) {
    int m = strlen(num1);
    int n = strlen(num2);

    int* res = calloc(m+n, sizeof(int));

    for ( int i = m-1; i>=0; i--)
    {
        for ( int j = n-1; j>=0; j--)
        {
            int a = num1[i] - '0';
            int b = num2[j] - '0';

            res[i+j+1] += a*b;
        }
    }

    for ( int i = m+n-1; i>0; i--)
    {
        res[i-1] += res[i]/10;
        res[i] %=10;
    }

    int s =0;
    while ( s <m+n-1 && res[s] == 0)
    {
        s++;
    }

    char* ans = malloc(m+n-s+1);
    int k = 0;
    for ( int i=s; i<m+n; i++)
    {
        ans[k++] = res[i] + '0';
    }
    ans[k] = '\0';
    free(res);
    return ans;
}
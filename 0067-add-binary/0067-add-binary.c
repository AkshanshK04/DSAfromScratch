char* addBinary(char* a, char* b) {
    int m = strlen(a)-1;
    int n = strlen(b)-1;
    int carry = 0;

    char* res = malloc((m+n+3)*sizeof(char));
    int k = m+n+2;
    res[k] = '\0';
    k--;

    while ( m>=0 || n>=0 || carry)
    {
        int sum = carry;
        if ( m>=0)
            sum += a[m--] -'0';
        if ( n>=0)
            sum += b[n--] -'0';
        res[k--] = sum%2 +'0';
        carry = sum/2;
    }

    return &res[k+1];
}
int myAtoi(char* s) {
    long long  x=0;
    int n=1, i=0;
    while ( s[i] == ' ')
        i++;
    
    if (s[i] == '-')
    {
        n=-1;
        i++;
    }
    else if (s[i] == '+')
        i++;
    
    while ( s[i]>='0' && s[i] <= '9')
    {
        x = x*10 + s[i] -'0';
        
        if (n==1 && x>INT_MAX)
            return INT_MAX;
        if (n==-1 && -x < INT_MIN)
            return INT_MIN;
        i++;
    }

    return (int)(n*x);
}
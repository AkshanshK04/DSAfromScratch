int divide(int dividend, int divisor) {
    if ( dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long long a = dividend;
    long long b = divisor;

    int sign = 1;

    if ( a<0)
    {
        sign = -sign;
        a = -a;
    }

    if ( b<0)
    {
        sign = -sign;
        b = -b;
    }

    long long q =0;
    while ( a>= b)
    {
        long long temp = b;
        long long count  =1;
        while ( a >= (temp<<1))
        {
            temp = temp<<1;
            count = count << 1;
        }
        a -= temp;
        q += count;
    }
    
    if ( sign <0)
        q = -q;

    return q;
}
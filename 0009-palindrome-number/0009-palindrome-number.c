bool isPalindrome(int x) {
    if ( x<0)
        return false;
    
    int prev = x;
    long long y = 0;
    while (x)
    {
        y = y*10+x%10;
        x /= 10;
    }

    if (prev==y)
        return true;
    else
        return false;
}
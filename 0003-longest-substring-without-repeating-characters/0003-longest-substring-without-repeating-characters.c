int lengthOfLongestSubstring(char* s) {
    int last[256] = {0};
    int count =0;
    int max = 0;
    for ( int i=0; s[i] != 0; i++)
    {
        if ( last[(unsigned char)s[i]] > count )
            count = last[(unsigned char)s[i]];

        last[(unsigned char)s[i]] = i+1;
        if ( i -count +1 > max)
            max = i - count +1;
    }

    return max;
}
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)
        return "";
    
    char* firststring = strs[0];
    for ( int i = 1; i<strsSize; i++)
    {
        int j = 0;
        while ( firststring[j] !='\0' && strs[i][j] !='\0' && firststring[j] == strs[i][j])
        {
            j++;
        }
        firststring[j] = '\0';
        if ( firststring[0] == '\0')
            return "";
    }
    return firststring;
}
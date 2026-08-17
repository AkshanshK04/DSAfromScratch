/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** res= malloc(wordsSize*sizeof(char*));
    int rescount = 0;
    int i = 0;

    while ( i< wordsSize)
    {
        int j = i;
        int linelen= 0;

        while ( j < wordsSize)
        {
            int newlen= linelen + strlen(words[j]);
            if ( j>i)
                newlen+=1;
            
            if ( newlen > maxWidth)
                break;
            
            linelen = newlen;
            j++;
        }

        int wordcount = j-i;
        int allspace = maxWidth;

        for ( int k =i; k<j ; k++)
            allspace -= strlen(words[k]);
        
        char* line = malloc(maxWidth + 1);
        int pos = 0;

        if ( j == wordsSize || wordcount ==1 )
        {
            for ( int k = i; k<j; k++)
            {
                int len = strlen(words[k]);
                memcpy (line + pos, words[k], len);
                pos+=len;

                if ( k < j-1)
                    line[pos++] = ' ';

            }

            while ( pos < maxWidth)
                line[pos++] = ' ';
        }

        else 
        {
            int gaps = wordcount - 1;
            int spaceingap = allspace / gaps;
            int extraspace = allspace % gaps;

            for (int k = i; k < j; k++) {
                int len = strlen(words[k]);

                memcpy(line + pos, words[k], len);
                pos += len;

                if (k < j - 1) {
                    int spaces = spaceingap;

                    if (extraspace > 0) {
                        spaces++;
                        extraspace--;
                    }

                    while (spaces--)
                        line[pos++] = ' ';
                }
            }
        }

        line[pos] = '\0';
        res[rescount++] = line;

        i = j;
        
    }

    *returnSize = rescount;
    return res;
}
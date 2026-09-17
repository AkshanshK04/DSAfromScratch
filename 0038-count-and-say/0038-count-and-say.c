char* countAndSay(int n) {
    char* curr = malloc(5000);
    strcpy(curr, "1");

    for ( int i=1; i<n; i++)
    {
        char* next = malloc(5000);
        int j=0, pos=0;

        while ( curr[j] != '\0')
        {
            char digit = curr[j];
            int count = 0;

            while ( curr[j] == digit)
            {
                count++;
                j++;
            }

            pos += sprintf(next +  pos, "%d%c", count, digit);

        }

        free(curr);
        curr = next;
    }

    return curr;
}
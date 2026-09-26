int numDecodings(char* s) {
    int p2 = 1;  
    int p1 = 1;  

    for (int i = 0; s[i] != '\0'; i++) 
    {
        int curr = 0;

        if (s[i] >= '1' && s[i] <= '9') 
            curr += p1;
        

        if (i > 0) 
        {
            int num = (s[i - 1] - '0') * 10 + (s[i] - '0');

            if (num >= 10 && num <= 26) 
            {
                curr += p2;
            }
        }

        p2 = p1;
        p1 = curr;
    }

    return p1;
}
bool checkString(char* s) {
    int seenb = 0;

    for (int i = 0; s[i] != '\0'; i++) 
    {
        if (s[i] == 'b') 
        {
            seenb = 1;
        }
        else if (s[i] == 'a' && seenb) 
        {
            return false;
        }
    }

    return true;
}
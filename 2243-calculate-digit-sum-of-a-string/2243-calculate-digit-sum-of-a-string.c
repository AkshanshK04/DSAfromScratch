char* digitSum(char* s, int k) {
    
    while (strlen(s) > k) 
    {
        char temp[1000];
        int sum = 0, j = 0;

        for (int i = 0; s[i]!= '\0'; i++) 
        {
            sum += s[i] - '0';

            if ((i + 1) %k == 0 || s[i+ 1]== '\0') 
            {
                char num[20];
                sprintf(num, "%d", sum);

                for (int p = 0; num[p] !='\0'; p++)
                    temp[j++] = num[p];

                sum = 0;
            }
        }

        temp[j] ='\0';
        strcpy(s, temp);
    }

    return s;
}
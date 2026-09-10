bool isValid(char* s) {
    int n = strlen(s);
    char* t = malloc(n*sizeof(char));
    int top = -1;
    for (int i= 0; i<n; i++)
    {
        char c = s[i];
        
        if ( c == '(' || c == '{' || c == '[')
            t[++top] = c;
        else 
        {
            if ( top == -1)
            {
                free(t);
                return false;
            }

            char open = t[top];

            if ( ( c == ')' && open != '(') ||
                ( c == '}' && open != '{')  ||
                ( c == ']' && open != '['))
            {
                free(t);
                return false;
            }

            top--;
        }
    }

    bool res = (top == -1);

    free(t);
    return res;
}
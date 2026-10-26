bool isIsomorphic(char* s, char* t) {
    int map1[256] = {0};
    int map2[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) 
    {
        unsigned char a = s[i];
        unsigned char b = t[i];

        if (map1[a] != map2[b])
            return false;

        map1[a] = i + 1;
        map2[b] = i + 1;
    }

    return true;
}
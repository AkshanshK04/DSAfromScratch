bool isPalindrome(char* s) {
    int l = 0;
    int r = 0;

    while (s[r] != '\0') {
        r++;
    }
    r--;

    while (l<r) {
        while (l<r && !isalnum((unsigned char)s[l])) {
            l++;
        }

        while (l<r && !isalnum((unsigned char)s[r])) {
            r--;
        }

        if (tolower((unsigned char)s[l]) !=
            tolower((unsigned char)s[r])) {
            return false;
        }

        l++;
        r--;
    }

    return true;
}
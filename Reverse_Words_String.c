// Time: O(n)
// Space: O(1)

void reverseString(char* s, int sSize) {
    int l=0, r=sSize-1;
    while (l<=r)
    {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

char* reverseWords(char* s) {
    int i = 0;
    unsigned int j = 0;

    while (j <= strlen(s))
    {
        if (*(s+j) == ' ' || *(s+j) == '\0')
        {
            reverseString(s+i, j-i);
            i = j+1;
        }
        j++;
    }
    
    reverseString(s, strlen(s));

    char* res = s;
    char* temp = s;

    while (*temp == ' ')
        temp++;

    while(*temp) {
        if (*temp != ' ' || (*(temp+1) != ' ' && *(temp+1) != '\0'))
            *res++ = *temp;
        temp++;
    }
    *res = '\0';

    return s;
}
// Time: O(n^2)
// Space: O(n)

void expand(char* s, char* res, int* resLen, int l, int r)
{
    while (l>=0 && r<strlen(s) && s[l] == s[r])
    {
        if ((r-l+1) > *resLen)
        {
            strncpy(res, s + l, r-l+1);
            res[r - l + 1] = '\0';
            *resLen = r-l+1; 
        }
        l--;
        r++;
    }
}

char* longestPalindrome(char* s) {
    char* res = (char*)malloc(sizeof(char)*(strlen(s)+1));
    int resLen = 0;

    for(int i=0; i<strlen(s); i++)
    {
        expand(s, res, &resLen, i, i); // odd
        expand(s, res, &resLen, i, i+1); // even
    }

    return res;
}
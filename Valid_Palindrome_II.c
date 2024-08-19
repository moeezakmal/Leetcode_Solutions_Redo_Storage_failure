// Time: O(n)
// Space: O(1)

bool isPalindrome(char* s, int l, int r);

bool validPalindrome(char* s) {
    int l=0;
    int r=strlen(s)-1;

    while (l<r) // middle character is always equal to itself (no need to check)
    {
        if (s[l] == s[r])
        {
            l++;
            r--;
        }

        if (s[l] != s[r])
            return (isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1));
    }
    return 1;
}

bool isPalindrome(char* s, int l, int r) {
    while (l<r) // middle character is always equal to itself (no need to check)
    {       
        if (s[l] == s[r])
        {
            l++;
            r--;
        }

        if (s[l] != s[r])
            return 0;
    }
    return 1;
}
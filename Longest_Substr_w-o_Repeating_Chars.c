// Time: O(n)
// Space: O(n)

int lengthOfLongestSubstring(char* s) {
    if (!s)
        return 0;

    int charASCII[256];
    memset(charASCII, -1, sizeof(charASCII));

    int l=0, res=0;
    
    for (int r=0; r<strlen(s); r++)
    {
        while(charASCII[s[r]] != -1)
        {
            charASCII[s[l]]--;
            l++;
        }
        charASCII[s[r]]++;
        res = (res>r-l+1) ? res : r-l+1;
    }
    return res;
}
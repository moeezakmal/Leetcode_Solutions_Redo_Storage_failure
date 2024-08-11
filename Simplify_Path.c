// Time: O(n) -> ~string length
// Space: O(2n) -> buffer + array => ~O(n)

char *simplifyPath(char *path) {
    
    char *arr[1000];
    unsigned arrIdx = 0;
   
    char cur[100];         // Buffer to hold the current token
    unsigned curIdx = 0;    // Index for the current token

    for (int i = 0; path[i] != '\0'; i++) 
    {
        char c = path[i];

        if (c == '/') 
        {
            if (curIdx > 0) 
            {
                cur[curIdx] = '\0'; // Terminate the current token
                
                if (strcmp(cur, "..") == 0) 
                {
                    if (arrIdx > 0) 
                        arrIdx--;  // Simulate pop operation
                } 
                else if (strcmp(cur, ".") != 0) 
                    arr[arrIdx++] = strdup(cur); // Simulate push operation
                
                curIdx = 0; // Reset current token buffer
            }
        } 
        else
            cur[curIdx++] = c; // Accumulate the character into cur  
    }

    // Handle the case for the last token (if the path doesn't end with '/')
    if (curIdx > 0) {
        cur[curIdx] = '\0';
        
        if (strcmp(cur, "..") == 0) {
            if (arrIdx > 0) {
                arrIdx--;  
            }
        } else if (strcmp(cur, ".") != 0) {
            arr[arrIdx++] = strdup(cur);        }
    }

    char *res = (char *)malloc(sizeof(char) * 3000);
    memset(res, 0, sizeof(char) * 3000);
    for (unsigned i = 0; i < arrIdx; i++) {
        strcat(res, "/");
        strcat(res, arr[i]);
    }
    if (strcmp(res, "") == 0)
        return "/";
    else
        return res;
}
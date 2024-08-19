// bool isalphanum(char x);


// bool isPalindrome(char* s) {
//     int l=0;
//     int r=strlen(s)-1;

//     // printf("%d", s[r]);

//     while (l<r) // middle character is always equal to itself (no need to check)
//     {
//         if (!isalphanum(s[l]))
//         {   
//             l++;
//             continue;
//         }

//         if (!isalphanum(s[r]))
//         {    
//             r--;
//             continue;
//         }
        
//         if (isalphanum(s[l]) && isalphanum(s[r]) && tolower(s[l])==tolower(s[r]))
//         {
//             l++;
//             r--;
//             continue;
//         }
    
//         return 0;
//     }

//     return 1;
// }


// bool isalphanum(char x) {
//     unsigned char uchar = (unsigned char) x;

//     if ('a' <= uchar && uchar <='z' || \
//         'A' <= uchar && uchar <='Z' || \
//         '0' <= uchar && uchar <='9' )
//         return 1;
//     return 0;
// }




// Refined version of the above code

// Time: O(n)
// Space: O(1)


bool isalphanum(char x);
char tolowercase(char x);


bool isPalindrome(char* s) {
    int l=0;
    int r=strlen(s)-1;

    // printf("%d", s[r]);

    while (l<r) // middle character is always equal to itself (no need to check)
    {
        if (!isalphanum(s[l]))
        {   
            l++;
            // continue;
        }

        if (!isalphanum(s[r]))
        {    
            r--;
            // continue;
        }
        
        if (isalphanum(s[l]) && isalphanum(s[r]) && tolowercase(s[l])==tolowercase(s[r]))
        {
            l++;
            r--;
            // continue;
        }

        if (isalphanum(s[l]) && isalphanum(s[r]) && tolowercase(s[l])!=tolowercase(s[r]))
            return 0;
    }

    return 1;
}


char tolowercase(char x) {
    unsigned char uchar = (unsigned char) x;
    
    if ('A' <= uchar && uchar <='Z')
        return uchar - ('A' - 'a');
    return uchar;
}


bool isalphanum(char x) {
    unsigned char uchar = (unsigned char) x;

    if ('a' <= uchar && uchar <='z' || \
        'A' <= uchar && uchar <='Z' || \
        '0' <= uchar && uchar <='9' )
        return 1;
    return 0;
}
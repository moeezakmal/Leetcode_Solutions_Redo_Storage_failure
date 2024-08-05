// Time: O(n)
// Space: O(26*2) -> O(1)

bool isAnagram(char* s, char* t) {
    int count1[26] = {0}, count2[26] = {0};

   if(strlen(s) != strlen(t))
	   return 0;

   for(int i=0; i<strlen(s); i++)
      count1[s[i] - 'a']++;
   
   for(int i=0; i<strlen(t); i++)
      count2[t[i] - 'a']++;
 
   for (int i=0; i < 26; i++)
    {
        if (count1[i] != count2[i])
            return 0;
    }
    return 1;
}
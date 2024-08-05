// Time: O(n)
// Space: O(1)


int reverse(int x){
    int res = 0;
    int max = INT_MAX;
    int min = INT_MIN;

    while (x != 0)
    {
        int temp = x%10;

        if ((res>max/10) || ((res==max/10) && temp >= max%10))
            return 0;
        if ((res<min/10) || ((res==min/10) && temp <= min%10))
            return 0;
        
        res = (res*10) + temp;
        x = x/10;
    }
    return res;
}
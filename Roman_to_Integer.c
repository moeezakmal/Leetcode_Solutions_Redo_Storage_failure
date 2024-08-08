// Time: O(1)
// Space: O(1)


int romanToInt(char* s) {
    int values[256]; // All ASCII values
    values['I'] = 1;
    values['V'] = 5;
    values['X'] = 10;
    values['L'] = 50;
    values['C'] = 100;
    values['D'] = 500;
    values['M'] = 1000;

    int sum = 0;
    int i = 0;
    while (i < strlen(s)) {
        int currentValue = values[s[i]];
        int nextValue = 0;
        if (i + 1 < strlen(s)) {
            nextValue = values[s[i + 1]];
        }
        if (currentValue < nextValue) {
            sum += (nextValue - currentValue);
            i += 2;
        } else {
            sum += currentValue;
            i += 1;
        }
    }
    return sum;
}
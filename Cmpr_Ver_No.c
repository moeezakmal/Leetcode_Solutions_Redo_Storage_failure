// Time: O(n + m + max(n,m))
// Space: O(n + m)


long strtolong(const char *str, char **endptr, int base) {
    // Skip leading whitespace
    while (isspace(*str)) {
        str++;
    }

    // Determine the base
    if (base == 0) {
        if (*str == '0') {
            if (tolower(*(str + 1)) == 'x') {
                base = 16; // Hexadecimal
                str += 2;
            } else {
                base = 8;  // Octal
            }
        } else {
            base = 10; // Decimal
        }
    } else if (base == 16 && *str == '0' && tolower(*(str + 1)) == 'x') {
        str += 2; // Skip "0x" for hexadecimal
    } else if (base < 2 || base > 36) {
        // Base out of range
        if (endptr) {
            *endptr = (char *)str;
        }
        return 0;
    }

    // Initialize variables
    long result = 0;
    int negative = 0;
    int digit;
    char c;

    // Handle optional sign
    if (*str == '-') {
        negative = 1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Convert characters to integer
    while ((c = *str) != '\0') {
        if (isdigit(c)) {
            digit = c - '0';
        } else if (isalpha(c)) {
            digit = tolower(c) - 'a' + 10;
        } else {
            break;
        }

        if (digit >= base) {
            break;
        }

        if (result > (LONG_MAX - digit) / base) {
            // Overflow or underflow
            result = (negative) ? LONG_MIN : LONG_MAX;
            break;
        }

        result = result * base + digit;
        str++;
    }

    if (endptr) {
        *endptr = (char *)str;
    }

    return negative ? -result : result;
}


int compareVersion(char* version1, char* version2) {
    // printf("%s\n", version1);
    // printf("%s\n", version2);
    // return 0;

    while (*version1 || *version2) {
        long num1 = strtolong(version1, &version1, 10);
        long num2 = strtolong(version2, &version2, 10);

        if (num1 > num2) return 1;
        if (num1 < num2) return -1;

        if (*version1) version1++;
        if (*version2) version2++;
    }

    return 0;
}
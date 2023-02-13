int charDecoder(char c) {
    if (c == 'I') {
        return 1;  
    }
    else if (c == 'V') {
        return 5; 
    }
    else if (c == 'X') {
        return 10; 
    }
    else if (c == 'L') {
        return 50; 
    }
    else if (c == 'C') {
        return 100; 
    }
    else if (c == 'D') {
        return 500; 
    }
    else if (c == 'M') {
        return 1000; 
    }
    return 0;
}

bool isSpecial(char curr, char next) {
    if (curr == 'I') {
        if (next == 'V' || next == 'X') {
            return true;
        }
    }
    else if (curr == 'X') {
        if (next == 'L' || next == 'C') {
            return true;
        }
    }
    else if (curr == 'C') {
        if (next == 'D' || next == 'M') {
            return true;
        }
    }
    return false;
}

int romanToInt(char* s) {
    int count = 0;
    int len = strlen(s);
    
    for (int x = 0; x < len; x++) {
        printf("%c", s[x]);
        if (x + 1 >= len) {
            count += charDecoder(s[x]);
        }
        else {
            if (isSpecial(s[x], s[x + 1])) {
                count += charDecoder(s[x + 1]) - charDecoder(s[x]);
                x++;
            }
            else {
                count += charDecoder(s[x]);
            }
        }
    }
    
    return count;
}
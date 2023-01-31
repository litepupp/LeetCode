int lengthOfLongestSubstring(char* s) {
    int max = 0;
    int temp = 0;
    
    for (int start = 0; start < strlen(s); start++) {
        for (int end = start; end < strlen(s); end++) {
            temp = (end - start) + 1;
            
            for (int x = start; x < end; x++) {
                for (int y = x + 1; y <= end; y++) {
                    if (s[x] == s[y]) {
                        temp = 0;
                        start++;
                        goto end;
                    }
                }
            }
end:
            if (temp > max) {
                max = temp;
            }
        }
    }
    
    return max;
}
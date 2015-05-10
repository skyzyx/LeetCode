int lengthOfLongestSubstring(char* s) {
    if (strlen(s) <= 1)
        return strlen(s);
        
    int prev = 0;
    int maxLen = 0;
    bool visited[256] = {false};
    
    for (int i = 0; i < strlen(s); i++) {
        if (visited[s[i]] == false)
            visited[s[i]] = true;
        else {
            while (s[i] != s[prev]) {
                visited[s[prev]] = false;
                prev++;
            }
            prev++;
        }
        
        if (i - prev + 1 > maxLen)
            maxLen = i - prev + 1;
    }
    return maxLen;
}
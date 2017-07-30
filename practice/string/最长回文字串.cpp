



int longestPalindrome(string s) {
    if (s.empty()) return 0;
    if (s.size() == 1) return 1;
    int  max_len = 1;      //
    for (int i = 0; i < s.size();) {
        if (s.size() - i <= max_len / 2) break;
        int j = i, k = i;       //j is a pre pointer,k is next pointer
        while (k < s.size() - 1 && s[k + 1] == s[k])
            ++k; // Skip duplicate characters.
        i = k + 1;
        while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) 
        {
            ++k; 
            --j; 
        } // Expand.
        if ( k - j + 1 > max_len) 
            max_len = k - j + 1; 
    }
    return  max_len;
}
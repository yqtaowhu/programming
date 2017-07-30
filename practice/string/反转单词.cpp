 void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int storeIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.erase(s.begin() + storeIndex, s.end());
    }
//最简单的方法，用辅助数组
void reverseWords(string &s) {
	        stringstream ss(s);
	        vector<string> v; string token;
	        while (getline(ss, token,' ')) {
		        if(token!="")                    //这里注意了！！！！！！！
		        	v.push_back(token);
    	    }
	         s = "";
	        for (int i = v.size() - 1; i >= 0; i--) {
	           	s += i != 0 ? v[i] + " " : v[i];
	     }

}
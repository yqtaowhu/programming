class Solution {
public:
    int StrToInt(string str) {
        for (int j = 0; j < str.size(); j++)
			if (isalpha(str[j])) 
                return 0;
		int i = 0, indicator = 1;
		long long int result = 0;
        //过滤空格
		while (str[i] == ' ') i++;
        //+ , - 号
		if (str[i] == '+' || str[i] == '-') {
			indicator = (str[i] == '-') ? -1 : 1;
			i++;
		}
		while (isdigit(str[i])) {
			int digit = str[i] - '0';
			result = result * 10 + digit;
			if (result*indicator >= INT_MAX) return INT_MAX;
			if (result*indicator <= INT_MIN) return INT_MIN;
			i++;
	}
	return indicator*result;
}
};

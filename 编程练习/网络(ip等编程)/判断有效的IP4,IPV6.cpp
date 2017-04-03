class Solution {
public:
const string validIPv6Chars = "0123456789abcdefABCDEF";
vector<string> split(string& str, char c) {
	vector<string> svec;
	stringstream ss(str); string token;
	while (getline(ss, token, c))
		svec.push_back(token);
	return svec;
}
bool isValid(string s) {
	if (s.empty()) return false;
	int num = 0;
	for (int i = 0; i<s.size(); i++) {
		char c = s[i];
		// special case: if c is a leading zero and there are characters left
		if (!isalnum(c) || (i == 0 && c == '0' && s.size() > 1))
			return false;
		else {
			num *= 10;
			num += c - '0';
		}
	}
	return num <= 255;
}

bool isValidIPV6(string s) {
	if (s.empty()) return false;
	if (s.size()>0 && s.size() <= 4) {
		for (int i = 0; i<s.size(); i++) {
			char c = s[i];
			if (validIPv6Chars.find(c) == string::npos)
				return false;
		}
		return true;
	}
    return false;
}

string validIPAddress(string IP) {
	string ans[3] = { "IPv4", "IPv6", "Neither" };
	vector<string>svec;
	// ipv4 candidate
	if (IP.substr(0, 4).find('.') != string::npos) {
		if (IP[IP.size() - 1] == '.') return ans[2];
		svec = split(IP, '.');
		if (svec.size() != 4) return ans[2];
		if (isValid(svec[0]) && isValid(svec[1]) && isValid(svec[2]) && isValid(svec[3]))
			return ans[0];
		else return ans[2];
	}
	// ipv6 candidate
	else if (IP.substr(0, 5).find(':') != string::npos) {
		if (IP[IP.size() - 1] == ':') return ans[2];
		svec = split(IP, ':');
		if (svec.size() != 8) return ans[2];
		for (int i = 0; i<8; i++) {
			if (!isValidIPV6(svec[i]))
				return ans[2];
		}
		return ans[1];

	}
	return ans[2];
}
};
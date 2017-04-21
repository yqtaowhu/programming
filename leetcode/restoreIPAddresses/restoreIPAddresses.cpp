// Date   : 2016.09.18
// Author : yqtao
// https://github.com/yqtaowhu
/********************************************************************************** 
* 
* Given a string containing only digits, restore it by returning all possible valid IP address combinations.
* 
* For example:
* Given "25525511135",
* 
* return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
* 
*               
**********************************************************************************/
class Solution {
public:
vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    int len = s.size();
    for(int i=1; i<4 && i<len-2; i++){
        for(int j=i+1; j<i+4 && j<len-1; j++){
            for(int k=j+1; k<j+4 && k<len; k++){
                if(len-k>3)
                    continue;
                string a = s.substr(0, i);
                string b = s.substr(i, j-i);
                string c = s.substr(j, k-j);
                string d = s.substr(k, len-k);
                if(isValid(a) && isValid(b) && isValid(c) && isValid(d))
                    res.push_back(a+'.'+b+'.'+c+'.'+d);
            }
        }
    }
    return res;
}
bool isValid(string s){
    if(atoi(s.c_str()) > 255 || (s[0] == '0' && s.size() > 1))
        return false;
    return true;
}
};

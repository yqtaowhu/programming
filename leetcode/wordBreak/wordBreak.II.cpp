// Author : yqtao
// Date   : 2016。09.23
// Email  : yqtao@whu.edu.cn

/********************************************************************************** 
* 
* Given a string s and a dictionary of words dict, add spaces in s to construct a sentence 
* where each word is a valid dictionary word.
* 
* Return all such possible sentences.
* 
* For example, given
* s = "catsanddog",
* dict = ["cat", "cats", "and", "sand", "dog"].
* 
* A solution is ["cats and dog", "cat sand dog"].
* 
*               
**********************************************************************************/
//reference:https://discuss.leetcode.com/topic/12997/11ms-c-solution-concise
class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
};
//memory limit 
vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector< vector<string> > result(s.size());

    for(int i=s.size()-1; i>=0; i--) {
        vector<string> v;
        result[i] = v;
        for(int j=i+1; j<=s.size(); j++) {
            string word = s.substr(i, j-i);
            if (dict.find(word) != dict.end()){
                if (j==s.size()){
                    result[i].push_back(word);
                }else{
                    for(int k=0; k<result[j].size(); k++){
                        result[i].push_back(word + " " + result[j][k]);
                    }
                }
            }
        } 
    }

    return result[0];
}


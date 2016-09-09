/***************************************************************************
*Given an array of strings, group anagrams together.
*
*For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
*Return:
*
*[
*  ["ate", "eat","tea"],
*  ["nat","tan"],
*  ["bat"]
*]
*
********************************************************************************/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].insert(s);
        }
        vector<vector<string>> anagrams;
        for (auto m : mp) { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};
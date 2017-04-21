// Date   : 2016.08.23
// Author : yqtao
// https://github.com/yqtaowhu
class Solution {
public:
   bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (int i = 0; i < magazine.size(); ++i)
            ++map[magazine[i]];
        for (int j = 0; j < ransomNote.size(); ++j)
            if (--map[ransomNote[j]] < 0)
                return false;
        return true;
    }
};
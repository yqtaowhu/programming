// Date   : 2016.10.08
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while preserving 
 * the order of characters. No two characters may map to the same character but a character
 *  may map to itself.
 * 
 * For example,
 *
 *     Given "egg", "add", return true.
 *     
 *     Given "foo", "bar", return false.
 *     
 *     Given "paper", "title", return true.
 * 
 * Note:
 * You may assume both s and t have the same length.
 *               
 **********************************************************************************/
//my way
//careful ab ,  aa    is return false;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;
        for (int i=0;i<s.size();i++) {
            if (map.find(s[i])==map.end()) {               //如果没有找到这个映射
                map[s[i]]=t[i];                            //添加映射
                for (int j=0;j<i;j++) {                    //查找是否有重复映射
                    if (map[s[j]]==map[s[i]]) return false;//如果有重复，则为假
                }
            }
            else {                                         //如果有此映射
                if (map[s[i]]!=t[i]) return false;         //看是否相等
            }
        }
        return true;
    }
};

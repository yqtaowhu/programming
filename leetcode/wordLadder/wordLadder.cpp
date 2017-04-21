// Date   : 2016.09.21
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given two words (start and end), and a dictionary, find the length of shortest 
* transformation sequence from start to end, such that:
* 
* Only one letter can be changed at a time
* Each intermediate word must exist in the dictionary
* 
* For example,
* 
* Given:
* start = "hit"
* end = "cog"
* dict = ["hot","dot","dog","lot","log"]
* 
* As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
* return its length 5.
* 
* Note:
* 
* Return 0 if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.
* 
*               
**********************************************************************************/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.erase(beginWord);
        wordDict.erase(endWord);
        unordered_set<string> nextWords;
        unordered_set<string> prevWords;
        nextWords.insert(beginWord);
        prevWords.insert(endWord);
        int ladder = 2, len = beginWord.length();
        while (!nextWords.empty() && !prevWords.empty()) {
            if (nextWords.size() > prevWords.size())
                swap(nextWords, prevWords);
            unordered_set<string>::iterator itr = nextWords.begin();
            unordered_set<string> temp;
            for (; itr != nextWords.end(); itr++) {
                string word = *itr;
                for (int p = 0; p < len; p++) {
                    char letter = word[p];
                    for (int j = 0; j < 26; j++) {
                        word[p] = 'a' + j; 
                        if (prevWords.find(word) != prevWords.end())
                            return ladder;
                        if (wordDict.find(word) != wordDict.end()) {
                            temp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[p] = letter;
                }
            }
            swap(nextWords, temp);
            ladder++; 
        }
        return 0;
    }
};

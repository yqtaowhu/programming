// Date   : 2016.09.25
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Design and implement a data structure for Least Recently Used (LRU) cache. 
* It should support the following operations: get and set.
* 
*    get(key) - Get the value (will always be positive) of the key if the key exists 
*               in the cache, otherwise return -1.
*
*    set(key, value) - Set or insert the value if the key is not already present. 
*                      When the cache reached its capacity, it should invalidate 
*                      the least recently used item before inserting a new item.
*               
**********************************************************************************/
//reference:https://discuss.leetcode.com/topic/6812/c-11-code-74ms-hash-table-list
//i dont understand this question
class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void set(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
			if (cache.size() == _capacity) {
				cache.erase(used.back());
				used.pop_back();
			}
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }
    
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;
    
    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
    
    HIPII cache;
    LI used;
    int _capacity;
};

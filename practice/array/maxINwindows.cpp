// slide window in a size
class Solution {
public:
  vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
	int n = num.size();
    if (n<=0||n<size||size==0) return vector<int>();
	vector<int>ret;
	for (int i = 0; i <= n - size; i++) {
		int maxElem = num[i];
		for (int j = i + 1; j<i + size; j++) {
			maxElem = max(maxElem, num[j]);
			
		}
		ret.push_back(maxElem);
	}
	return ret;
}
};
//another way,using deque,the first index is the largest in the window
class Solution {
public:
  vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        int len = num.size();
        if (len <= 0 || size > len) return vector<int>();
        deque<int> deq;vector<int> res;
        for (int i=0;i<len;i++) {
            while (!deq.empty()&&num[deq.back()]<=num[i])
                deq.pop_back();
            deq.push_back(i);
            if (i-deq.front()==size) deq.pop_front();
            if (i>=size-1) res.push_back(num[deq.front()]);
        }
        return res;
    }
};

//全排列问题，没有重复数据
//回溯解法
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > vv;
        vector<int> v;
	    help(num,vv,v);
	    return vv;
    }
    void help(vector<int>& num,vector<vector<int>>& vv,vector<int>& v){
        if(v.size()==num.size()){
            vv.push_back(v);
            return;
        }
        for(int i=0;i<num.size();i++){
            if(find(v.begin(),v.end(),num[i])==v.end()) {
                v.push_back(num[i]);
                help(num,vv,v);
                v.pop_back();
            }
        }
    }
};
//如有重复数字
//回溯解法
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
	    vector<vector<int> > vv;
        vector<int> v;
        sort(nums.begin(),nums.end());
        vector<bool>vis(nums.size(),false);
	    help(nums,vv,v,vis);
	    return vv;
    }
    void help(vector<int>& num,vector<vector<int>>& vv,vector<int>& v,vector<bool>& vis){
        if(v.size()==num.size()){
            vv.push_back(v);
            return;
        }
        for(int i=0;i<num.size();i++){
            if(!vis[i]){
                if(i>0 &&num[i]==num[i-1]&&vis[i-1])
                    return;
                vis[i]=true;
                v.push_back(num[i]);
                help(num,vv,v,vis);
                v.pop_back();
:x                vis[i]=false;
            }
        }
    }
};
//迭代解法，无重复数字
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int> > vv;
	vv.push_back(num);
	if (num.size() <2) 
		return vv;
	int pos = 0;
	//与pos位置进行交换
	while (pos<num.size() - 1) {
		int size = vv.size();
		for (int i = 0; i<size; i++) {
			//take each number to the first place
			for (int j = pos + 1; j<vv[i].size(); j++) {
				vector<int> v = vv[i];
			    swap(v[j],v[pos]);
				vv.push_back(v);
			}
		}
		pos++;
	}
	return vv;
}
}
;
//无重复数字
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int> > vv;
       vv.push_back(nums);
       if (nums.size() <2)  return vv;  
       int pos=0;
       while(pos<nums.size()-1){
       int size = vv.size();
          for(int i=0; i<size; i++){
            //sort the array, so that the same number will be together
           sort(vv[i].begin()+pos, vv[i].end());
            //take each number to the first
            for (int j=pos+1; j<vv[i].size(); j++) {
                vector<int> v = vv[i];
                //skip the same number 
                if (j>0 && v[j]==v[j-1]){
                    continue;
                }
                swap(v[j],v[pos]);
                vv.push_back(v);
            }
        }
        pos++;
    }
    return vv;  
    }
};
//next permute
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty()) return;
        int n = nums.size();
        int i;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])
                break;
        }
        int j;
        if(i>=0) {
            for(j=n-1;j>i;j--) {
                if(nums[j]>nums[i])
                    break;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};

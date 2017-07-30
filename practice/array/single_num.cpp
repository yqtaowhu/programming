//only a num have once,others 2 times
int singleNumber(vector<int>& nums) {
        if(nums.empty())
            return -1;
        int ret = 0;
        for(auto c:nums)
            ret ^= c;
        return ret;
}
//can using stl accumulate
int singleNumber(vector<int>& nums) {
	return accumulate(nums.begin(),nums.end(),0,[](const int& a,const int& b){
        return a^b;});
}

//verify a sequence is a bst tree post travesal
class Solution {
public:
    bool verifyBTS(vector<int> vec,int begin,int end)
    {
        int i=end,j;
        if(begin>=end) return true;
        while(i>begin&&vec[i-1]>vec[end])
            i--;
        for(int j = begin;j<i;j++)
            if(vec[j]>vec[end])
                return false;
     return verifyBTS(vec,begin,i-1)&&verifyBTS(vec,i,end-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.size()==0) return false;
    if(sequence.size()==1) return true;
    return verifyBTS(sequence,0,sequence.size()-1);
    }
};
// verify a string is preorder
// using #include<sstream>      !!!!
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty())
            return false;
        stringstream ss(preorder);
        string token;
        vector<string> str;
        while(getline(ss,token,',')){
            str.push_back(token);
        }
        // careful !!!!!!!!!
        if(str.size()>1 && str[0]=="#")
            return false;
        if(str.size()==1 && str[0]=="#")
            return true;
        // if first is not # ,have two empty to insert
        int have = 2;
        for(int i=1;i<str.size();i++){
            if(--have<0)
                return false;
            if(str[i] !="#") {
                have += 2;
            }
        }
        return have == 0;
    }
};
//verify a seq is a seq pop sequence
//remember should using a stack
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        int len=pushV.size();
        int i=0,j=0;
        while(i<len&&j<len) {
			if (pushV[i]==popV[j]) {
                i++;j++;
            }
            else if (st.size()>0&&st.top()==popV[j]) {
				st.pop();
                j++;
            }
            else  {
				st.push(pushV[i]);
                i++;
            }
        }
        while (j<len) {
			if (st.top()!=popV[j]) 
                return false;
            j++;
            st.pop();
        }
        return true; 
}

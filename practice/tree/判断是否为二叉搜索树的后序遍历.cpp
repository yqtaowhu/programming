 
 
 
	bool verifyBTS(vector<int> vec,int begin,int end){
        int i=end,j;
        if(begin>=end) return true;
        while(i>begin&&vec[i-1]>vec[end])
            i--;
        for(int j = begin;j<i;j++)
            if(vec[j]>vec[end])
                return false;
     return verifyBTS(vec,begin,i-1)&&verifyBTS(vec,i,end-1);   //µÝ¹éµ÷ÓÃ
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.size()==0) return false;
    if(sequence.size()==1) return true;
    return verifyBTS(sequence,0,sequence.size()-1);
    }
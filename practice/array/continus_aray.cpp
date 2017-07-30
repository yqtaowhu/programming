//https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//思路很重
class Solution {
public:
   bool IsContinuous( vector<int> numbers ) {
        int n=numbers.size();
        if(n!=5)  return false;
        sort(numbers.begin(),numbers.end());
        int jokers=0;
        for(int i=0;i<5&&numbers[i]==0;i++) jokers++;
        if(jokers>4) return false;
       	//判断是否有重复的数字出现
        for(int i=jokers+1;i<5;i++)
            if(numbers[i]==numbers[i-1])
                return false;
        return (numbers[4]-numbers[jokers])<=4;
        
    }
};

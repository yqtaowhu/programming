
/**********************************************************************
链接：https://www.nowcoder.com/questionTerminal/138f0ae35154438caf3d0072bd6ffef5
来源：牛客网

对于三个字符串A，B，C。我们称C由A和B交错组成当且仅当C包含且仅包含A，B中所有字符，
且对应的顺序不改变。请编写一个高效算法，判断C串是否由A和B交错组成。
	给定三个字符串A,B和C，及他们的长度。请返回一个bool值，代表C是否由A和B交错组成。保证三个串的长度均小于等于100。
	测试样例：
	"ABC",3,"12C",3,"A12BCC",6
	返回：true
************************************************************************************/
//递归
class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
        if(n+m!=v) return false;
        if ((n==0&&B==C)||(m==0&&A==C)) return true;
        if ((n==0&&B!=C)||(m==0&&A!=C)) return false;
        if (A[0]!=C[0]&&B[0]==C[0])
            return chkMixture(A,n,B.substr(1),m-1,C.substr(1),v-1);
        else if (A[0]==C[0]&&B[0]!=C[0])
            return chkMixture(A.substr(1),n-1,B,m,C.substr(1),v-1);
        else if (A[0]==C[0]&&B[0]==C[0])
            return chkMixture(A.substr(1),n-1,B,m,C.substr(1),v-1)||
            	   chkMixture(A,n,B.substr(1),m-1,C.substr(1),v-1);
        else return false;
    }
};

//dp
class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
        // write code here
        if(n+m!=v)return false;
    
        vector<vector<bool>> dp (n+1,vector<bool>(m+1,false));
          
        int a=0;
        int b=0;
        dp[0][0] = true;
        for(int i=0;i<v;i++){
            if(A[a] == C[i] && dp[a][b] == true){
                a++;
                dp[a][b] = true;
            }
              
            if(B[b] == C[i] && dp[a][b] == true){
                b++;
                dp[a][b] = true;
            }
        }
        return dp[n][m];
          
    }
};
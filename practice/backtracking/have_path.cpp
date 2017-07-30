class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        vector<bool>visit(strlen(matrix),false);
    	for (int i=0;i<rows;i++) {
            for (int j=0;j<cols;j++) {
				int len=strlen(str);
                if (check(matrix,i,rows,j,cols,0,visit,str)) 
                    return true;
            }
        }
        return false;
    }
    bool check(char* matrix,int i,int rows,int j,int cols,int k,vector<bool>& visit,char* str) {
        int index=i*cols+j;
        if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || visit[index] ==true)
            return false;
        if (k==strlen(str)-1) return true;
        visit[index]=true;
        if (check(matrix, i-1,rows,j,cols, k + 1, visit,str)
                || check(matrix, i,rows,j-1,cols, k + 1, visit,str)
                || check(matrix, i,rows,j+1,cols, k + 1, visit,str)
                || check(matrix, i+1,rows,j,cols, k + 1, visit,str)) 
            return true;
        visit[index] = 0;  //回溯
        return false;
    }
	

};

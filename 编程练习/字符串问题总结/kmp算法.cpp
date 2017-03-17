



class StringPattern {
public:
    vector<int> getNextArray(string p) {
        vector<int>next(p.size());
        next[0]=-1;
        int k=-1,j=0;
		while (j<p.size()-1) {
            if (k==-1||p[k]==p[j]) {
                k++;j++;
                if (p[k]!=p[j]) next[j]=k;
                else next[j]=next[k];
            }
            else k=next[k];
        }
        return next;
    }
    int findAppearance(string A, int lena, string B, int lenb) {
        if (lena<lenb) return -1;
        int i=0,j=0;
        vector<int>next=getNextArray(B);
        while (i<lena&&j<lenb) {
            if (j==-1||A[i]==B[j]) {
			   ++i;++j;
            }
            else j=next[j];
        }
        return lenb==j ? i-j : -1;
    }
};
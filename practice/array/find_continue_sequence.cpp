class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if (sum<3) return res;
        int p1=1,p2=2;
        while (p1<p2) {
            //求和公式（a1+an)n/2
            int cur=(p1+p2)*(p2-p1+1)/2;
            if (cur==sum) {
                vector<int>tmp;
                for (int i=p1;i<=p2;i++) tmp.push_back(i);
                res.push_back(tmp);
                p1++;
            }
            else if (cur>sum) p1++;
            else p2++;
        }
        return res;
    }
};

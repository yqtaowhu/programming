//verify wheather b is a subtree
//should konw this logic
class Solution {
public:
    bool HasSubtree(TreeNode* p1, TreeNode* p2) {
        if(p1==NULL||p2==NULL) return false;
        return Hbtree(p1,p2);
    }
    bool Hbtree(TreeNode* p1, TreeNode* p2){
        if(p2==NULL) return true;
        if(p1==NULL) return false;
        if(p1->val==p2->val){
             if(Hbtree(p1->left,p2->left)&&Hbtree(p1->right,p2->right)) return true;
        }
        return Hbtree(p1->left,p2)||Hbtree(p1->right,p2);    
    }
};


链接：https://www.nowcoder.com/questionTerminal/6e196c44c7004d15b1610b9afca8bd88?toCommentId=190119
来源：牛客网

class Solution {
public:
   string serialize(TreeNode* root) {
    if (root == nullptr) return "#";
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    vector<int> getNext(string p) {
        int n = p.size();
        vector<int>next(n); next[0] = -1;
        int k = -1, j = 0;
        while (j<n - 1) {
        if (k==-1||p[j] == p[k]) {
            ++j; ++k;
            if (p[j] != p[k]) next[j] = k;
            else next[j] = next[k];       //优化next数组
        }
        else k = next[k];
    }
    return next;
    }
bool kmp(string s, string p, vector<int>& next) {
    int i = 0, j = 0, slen = s.size(), plen = p.size();
    while (i<slen&&j<plen) {
        if (j == -1 || s[i] == p[j]) {
            i++; j++;
        }
        else j = next[j];
    }
    return j == plen;
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot1 == nullptr || pRoot2 == nullptr) return false;
    string s = serialize(pRoot1);
    string p = serialize(pRoot2);
    vector<int>next = getNext(p);
    return kmp(s, p, next);
}
};

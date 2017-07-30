
// 输出二叉树的路径

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

class Solution {
public:
    vector<string> res;
    void dfs(TreeNode* root,string s) {
        s+="->"+to_string(root->val);
        if (root->left==NULL&&root->right==NULL) {
            res.push_back(s);
        }
        else {
            if (root->left) dfs(root->left,s);
            if (root->right) dfs(root->right,s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return res;
        dfs(root,"");
        for (int i=0;i<res.size();i++) 
            res[i].erase(res[i].begin(),res[i].begin()+2);
        return res;
    }
};
// 是否有和为特定值的路径
 //迭代
class Solution {
public:
     bool hasPathSum(TreeNode *root, int sum) {
        if (root==NULL) return false;
        vector<TreeNode*> v;
        v.push_back(root);
        while(v.size()>0){
            TreeNode* node = v.back();
            v.pop_back();
            if (node->left==NULL && node->right==NULL){
                if (node->val == sum){
                    return true;
                }
            }
            if (node->left){
                node->left->val += node->val;
                v.push_back(node->left);
            }
            if (node->right){
                node->right->val += node->val;
                v.push_back(node->right);
            }
        }
        return false;
        
    }
};
//递归
bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }

// 二叉树的和为为特定值，dfs+回溯,找全
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int>>paths;
        vector<int>path;
        findpaths(root,expectNumber,path,paths);
        return paths;
    }
    void findpaths(TreeNode* root,int sum,vector<int>& path,vector<vector<int>>& paths) {
        if (!root) return ;
        path.push_back(root->val);
        if (!root->left&&!root->right&&root->val==sum)
            paths.push_back(path);
        findpaths(root->left,sum-root->val,path,paths);
        findpaths(root->right,sum-root->val,path,paths);
        path.pop_back();
    }
};
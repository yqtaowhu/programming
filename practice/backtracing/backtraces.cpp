//find paths that sum path is a expect number
//using backtrace
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

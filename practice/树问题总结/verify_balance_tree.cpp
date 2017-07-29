class Solution {
public:
    int depth(TreeNode* root){
    	return root ? max(depth(root->left),depth(root->right))+1:0;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(!pRoot) 
            return true;
        int left = depth(pRoot->left);
        int right = depth(pRoot->right);
        return abs(left-right)<=1&&IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }
};

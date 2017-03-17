class Solution {
public:
    int depth (TreeNode *pRoot) {
        if (pRoot == NULL) return 0;
        return max (depth(pRoot -> left), depth (pRoot -> right)) + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == NULL) return true;
        int left=depth(pRoot->left);       //其左子树的最大深度
        int right=depth(pRoot->right);     //右子树的最大深度
        //分别遍历左子树，和右子树
        return abs(left - right) <= 1 && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);    
    }
};
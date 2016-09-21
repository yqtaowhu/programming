// Date   : 2016.09.21
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a binary tree, find the maximum path sum.
* 
* The path may start and end at any node in the tree.
* 
* For example:
* Given the below binary tree,
* 
*        1
*       / \
*      2   3
* 
* Return 6.
* 
*               
**********************************************************************************/
//reference:https://discuss.leetcode.com/topic/5508/simple-o-n-algorithm-with-one-traversal-through-the-tree
//每次找到一个顶点的最大值，如果其小于0,则不包含这个点，让其为0
//其包含任意的结点，而不是必须以叶子结点为开头和结尾。
class Solution {
    int maxToRoot(TreeNode *root, int &re) {
        if (!root) return 0;
        int l = maxToRoot(root->left, re);
        int r = maxToRoot(root->right, re);
        if (l < 0) l = 0;
        if (r < 0) r = 0;
        if (l + r + root->val > re) re = l + r + root->val;
        return root->val += max(l, r);
    }
public:
    int maxPathSum(TreeNode *root) {
        int max = INT_MIN;
        maxToRoot(root, max);
        return max;
    }
};
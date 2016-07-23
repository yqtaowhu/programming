// Date   : 2016.07.23
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
* such that adding up all the values along the path equals the given sum.
* 
* For example:
* Given the below binary tree and sum = 22,
* 
*               5
*              / \
*             4   8
*            /   / \
*           11  13  4
*          /  \      \
*         7    2      1
* 
* return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*               
**********************************************************************************/

#include <time.h>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool hasPathSum1(TreeNode *root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
    
   bool  hasPathSum2(TreeNode *root, int sum){
    if(!n) return false;
    stack<TreeNode *> st;
    TreeNode *cur = root, *pre;
    while(cur || !st.empty()){
        while(cur){
            st.push(cur);
            sum -= cur->val;
            cur = cur->left;
        }
        cur = st.top();
        if(!cur->left && !cur->right && !sum) return true;
        if(cur->right && pre != cur->right) cur = cur->right;
        else{
            st.pop();
            sum += cur->val;
            pre = cur;
            cur = NULL;
        }
    }
    return false;
	}
    
};

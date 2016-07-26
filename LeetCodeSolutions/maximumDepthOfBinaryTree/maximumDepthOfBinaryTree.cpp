// Date   : 2016.07.26
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a binary tree, find its maximum depth.
* 
* The maximum depth is the number of nodes along the longest path from the root node 
* down to the farthest leaf node.
*               
**********************************************************************************/

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
	//递归的方法，仅仅一行
	int maxDepth(TreeNode *root) {
        return root ? max(maxDepth(root->left),maxDepth(root->right))+1 :0;   
     }
	//层序遍历
    int maxDepth(TreeNode *root) {
		if (!root) return 0;
        queue<TreeNode*>que;
        que.push(root);
        TreeNode* last=root;
        int level=0;
        while (!que.empty()) {
            root=que.front();
            que.pop();
            if (root->left) que.push(root->left);
            if (root->right) que.push(root->right);
            if (last==root) {
                level++;
                last=que.back();
            }
        }
        return level;
    }
    
};

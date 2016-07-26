// Date   : 2016.07.26
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a binary tree, find its minimum depth.
* 
* The minimum depth is the number of nodes along the shortest path from the root node 
* down to the nearest leaf node.
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
	//solution 1，
    int minDepth(TreeNode *root) {
        if (root==NULL){
            return 0;
        }
        if (root->left==NULL && root->right==NULL){
            return 1;
        }
        int left=INT_MAX;
        if (root->left){
            left = minDepth(root->left) + 1 ;
        }
        int right=INT_MAX;
        if (root->right){
            right = minDepth(root->right) + 1;
        }
        
        return left<right ? left : right;
        
    }
	//the next version,very concise
	 int minDepth(TreeNode* root) {
		if(!root)                       return 0;
		if(root->left && root->right)   return min(minDepth(root->left),minDepth(root->right))+1;
		else                            return max(minDepth(root->left),minDepth(root->right))+1;
    }
	//solution 2 ，using BFS
	int minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    queue<TreeNode*> que;
    que.push(root);
    int i = 0;
    while (!que.empty()) {
        i++;
        int k = que.size();
        for (int j=0; j<k; j++) {
            TreeNode* rt = que.front();
            if (rt->left) que.push(rt->left);
            if (rt->right) que.push(rt->right);
            que.pop();
            if (rt->left==NULL && rt->right==NULL) return i;
        }
    }
	return -1; 
	}
};

// Date   : 2016.07.27
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a binary tree, return the zigzag level order traversal of its nodes' values. 
* (ie, from left to right, then right to left for the next level and alternate between).
* 
* For example:
* Given binary tree {3,9,20,#,#,15,7},
* 
*     3
*    / \
*   9  20
*     /  \
*    15   7
* 
* return its zigzag level order traversal as:
* 
* [
*   [3],
*   [20,9],
*   [15,7]
* ]
* ************************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //very easy ,just level traversal,and reverse it .
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int> res;vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode *last=root;
        while (que.size()>0) {
            root=que.front();
            que.pop();
            res.push_back(root->val);
            if (root->left) que.push(root->left);
            if(root->right) que.push(root->right);
            if (last==root) {
                result.push_back(res);
                last=que.back();
                res.clear();
            }
        }
        for (int i=1;i<result.size();i+=2)
            reverse(result[i].begin(),result[i].end());
        return result;
    }
};




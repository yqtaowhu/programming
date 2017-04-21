//Data    ：2016.07.2016
//Author  ：yqtao
/********************************************************************************** 
* 
* Given a binary tree, return the inorder traversal of its nodes' values.
* 
* For example:
* Given binary tree {1,#,2,3},
* 
*    1
*     \
*      2
*     /
*    3
* 
* return [1,3,2].
* 
* Note: Recursive solution is trivial, could you do it iteratively?
* 
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>result;
       stack<TreeNode*>st;
       while (st.size()>0||root) {
           if (root) {
               st.push(root);
               root=root->left;
           }
           else {
               if (st.size()) {
                   root=st.top();
                   st.pop();
                   result.push_back(root->val);
                   root=root->right;
               }
           }
       }
       return result;
    }
};

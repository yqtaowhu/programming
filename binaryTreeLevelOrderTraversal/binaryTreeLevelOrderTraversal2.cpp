/********************************************************************************** 
* 
* Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
* (ie, from left to right, level by level from leaf to root).
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
* return its bottom-up level order traversal as:
* 
* [
*   [15,7],
*   [9,20],
*   [3]
* ]
* 
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
* 
* OJ's Binary Tree Serialization:
* 
* The serialization of a binary tree follows a level order traversal, where '#' signifies 
* a path terminator where no node exists below.
* 
* Here's an example:
* 
*    1
*   / \
*  2   3
*     /
*    4
*     \
*      5
* 
* The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 
* 
*               
**********************************************************************************/
//this problem is very very similar with before,just reverse the vector
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector< vector<int> > vv;
    if(root == NULL) return vv;

    int level = 0; // current level.
    TreeNode *last = root; // last node of currrent level.
    queue<TreeNode*> q;

    q.push(root);
    vv.push_back(vector<int>());
    while(!q.empty()) {
        TreeNode *p = q.front();
        q.pop();

        vv[level].push_back(p->val);
        if(p->left ) q.push(p->left);
        if(p->right) q.push(p->right);

        if(p == last) {
            level++;
            last = q.back();
            vv.push_back(vector<int>()); // new buffer for next row.
        }
    }
    vv.pop_back();
    reverse(vv.begin(), vv.end());
    return vv;
    }
};
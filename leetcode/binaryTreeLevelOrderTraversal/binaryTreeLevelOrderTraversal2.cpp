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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector< vector<int> > vv;
    if(root == NULL) return vv;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()) {
        int size=que.size();
        vector<int>row(size);
        for (int i=0;i<size;i++) {
            TreeNode *p = que.front();
            que.pop();
            row[i]=p->val;
            if (p->left) que.push(p->left);
            if (p->right) que.push(p->right);
        }
        vv.push_back(row);
    }
    reverse(vv.begin(), vv.end());
    return vv;
    }
};
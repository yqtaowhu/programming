// Date   : 2016.07.27
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a binary tree, determine if it is a valid binary search tree (BST).
* 
* Assume a BST is defined as follows:
* 
* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.
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

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//travel the tree by inner-order
bool isValidBST(TreeNode* root) {
	vector<int>result;
	stack<TreeNode*>st;
	while (root || st.size()>0) {
		if (root) {
			st.push(root);
			root = root->left;
		}
		else {
			if (st.size()>0) {
				root = st.top();
				st.pop();
				result.push_back(root->val);
				root = root->right;
			}
		}
	}
	int t = result.size()-1;  //这里要注意了，不能直接写i<return.size()-1会出错
	for (int i = 0; i<t; i++) {
		if (result[i] >= result[i + 1])
			return false;
	}
	return true;
}
// recursive solution
bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
}
bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if(!root) return true;
    if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
        return false;
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}


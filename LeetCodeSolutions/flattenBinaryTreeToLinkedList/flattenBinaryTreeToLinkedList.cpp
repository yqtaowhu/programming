// Date   : 2016.09.20
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a binary tree, flatten it to a linked list in-place.
* 
* For example,
* Given
* 
*          1
*         / \
*        2   5
*       / \   \
*      3   4   6
* 
* The flattened tree should look like:
* 
*    1
*     \
*      2
*       \
*        3
*         \
*          4
*           \
*            5
*             \
*              6
* 
* 
* Hints:
* If you notice carefully in the flattened tree, each node's right child points to 
* the next node of a pre-order traversal.
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
 //reference:https://discuss.leetcode.com/topic/3995/share-my-simple-non-recursive-solution-o-1-space-complexity
 //O(1) space-complexity
class Solution {
public:
    void flatten(TreeNode *root) {
		TreeNode*now = root;
		while (now) {
			if(now->left) {
                //Find current node's prenode that links to current node's right subtree
				TreeNode* pre = now->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = now->right;
                //Use current node's left subtree to replace its right subtree(original right 
                //subtree is already linked by current node's prenode
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
    }
};
//very easy to understand ,but it O(N)space-complexity
class Solution {
public:
    void flatten(TreeNode *root) {
		vector<TreeNode*> st,v;
		st.push_back(root);
		while(!st.empty()) {
		    TreeNode* node=st.back();
		    st.pop_back();
		    v.push_back(node);
		    if (node&&node->right) st.push_back(node->right);
		    if (node&&node->left) st.push_back(node->left);
		}
		v.push_back(nullptr);
		for(int i=0; i<v.size(); i++){
            if (v[i]){
                v[i]->left = NULL;
                v[i]->right = v[i+1];
            }
        }
    }
};

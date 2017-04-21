// Date   : 2016.08.08
// Author : yqtao
// https://github.com/yqtaowhu


/********************************************************************************** 
 * 
 * Given a complete binary tree, count the number of nodes.
 * 
 * Definition of a complete binary tree from Wikipedia:
 * http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees
 *
 * In a complete binary tree every level, except possibly the last, is completely filled, 
 * and all nodes in the last level are as far left as possible. 
 * It can have between 1 and 2^h nodes inclusive at the last level h.
 *               
 **********************************************************************************/


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
    int height(TreeNode* root) {
	 return root == nullptr ? -1 : 1 + height(root->left);
	}
	int countNodes(TreeNode* root) {
	 int h = height(root);
	 return h < 0 ? 0 :
		 height(root->right) == h - 1 ? (1 << h) + countNodes(root->right)
		 : (1 << h - 1) + countNodes(root->left);
	}
};

//
class Solution {
public:
  int height(TreeNode* root) {
        return root == nullptr ? -1 : 1 + height(root->left);
    }
   int countNodes(TreeNode* root) {
        int nodes = 0, h = height(root);
        while (root != nullptr) {
            if (height(root->right) == h - 1) {
                nodes += 1 << h;
                root = root->right;
            } else {
                nodes += 1 << h-1;
                root = root->left;
            }
            h--;
        }
        return nodes;
    }
};
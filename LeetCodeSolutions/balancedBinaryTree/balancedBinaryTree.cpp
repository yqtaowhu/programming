// Source : https://oj.leetcode.com/problems/balanced-binary-tree/
// Author : Hao Chen
// Date   : 2014-06-28

/********************************************************************************** 
* 
* Given a binary tree, determine if it is height-balanced.
* 
* For this problem, a height-balanced binary tree is defined as a binary tree in which 
* the depth of the two subtrees of every node never differ by more than 1.
* 
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
 //第一种方法，从上到下，
class Solution {
public:
   int depth (TreeNode *root) {
        if (root == NULL) return 0;
        return max (depth(root -> left), depth (root -> right)) + 1;
    }

    bool isBalanced (TreeNode *root) {
        if (root == NULL) return true;
        
        int left=depth(root->left);       //其左子树的最大深度
        int right=depth(root->right);     //右子树的最大深度
        //在分别遍历左子树，和右子树
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);    
    }

};

//Notes: 
//The second method is based on DFS. 
//Instead of calling depth() explicitly for each child node, 
//we return the height of the current node in DFS recursion. 
//When the sub tree of the current node (inclusive) is balanced, 
//the function dfsHeight() returns a non-negative value as the height. 
//Otherwise -1 is returned. According to the leftHeight and rightHeight of the two children, 
//the parent node could check if the sub tree
//is balanced, and decides its return value.
class Solution {
public:
    int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return dfsHeight (root) != -1;
    }

};

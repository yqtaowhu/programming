// Date   : 2016.07.26
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given inorder and postorder traversal of a tree, construct the binary tree.
* 
* Note:
* You may assume that duplicates do not exist in the tree.
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//递归的方法
class Solution {
public:
    TreeNode* helper(vector<int>& inorder,int i,int j, vector<int>& postorder,int ii,int jj) {
        if (i>j||ii>jj) return NULL;
        int mid=postorder[jj];
        TreeNode* root=new TreeNode(mid);
        int index=0;
        for ( index=i;index<=j;index++) {
            if (inorder[index]==mid)
                break;
        }
        int dis=index-i; //步数
        root->left=helper(inorder,i,i+dis-1,postorder,ii,ii+dis-1);
        root->right=helper(inorder,i+dis+1,j,postorder,ii+dis,jj-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};



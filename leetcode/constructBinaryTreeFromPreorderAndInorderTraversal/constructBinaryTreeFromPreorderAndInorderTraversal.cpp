// Date   : 2016.07.26
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given preorder and inorder traversal of a tree, construct the binary tree.
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
//最为普遍的一种方法，递归
class Solution {
public:
    TreeNode* helper(vector<int>& preorder,int i,int j, vector<int>& inorder,int ii,int jj) {
        if (i>j||ii>jj) return NULL;//终止条件
        int mid=preorder[i]   ;//根节点
        TreeNode* root=new TreeNode(mid);
        int index; 
        for (index=ii;index<=jj;index++) {
            if (inorder[index]==mid)   //寻找根节点相同的值
                break;
        }
        int dis=index-ii;   //加上距离会使得，程序清晰
        root->left=helper(preorder,i+1,i+dis,inorder,ii,ii+dis-1);
        root->right=helper(preorder,i+dis+1,j,inorder,ii+dis+1,jj);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};


//下面是用STL中的find函数寻找，这里要注意的就是边界问题。
class Solution {

public:
    /* from Preorder and Inorder Traversal */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    
    }
	//这里的i，j为其某一个遍历开始的地方，和结束的地方
    TreeNode* helper(vector<int>& preorder,int i,int j,vector<int>& inorder,int ii,int jj)
    {
        // tree        8 4 5 3 7 3
        // preorder    8 [4 3 3 7] [5]
        // inorder     [3 3 4 7] 8 [5]

        // 每次从 preorder 头部取一个值 mid，作为树的根节点
        // 检查 mid 在 inorder 中 的位置，则 mid 前面部分将作为 树的左子树，右部分作为树的右子树

        if(i >= j || ii >= j)
            return NULL;

        int mid = preorder[i];
		//需要注意STL的规则是左闭右开，因此需要注意的是查找范围的问题
        auto f = find(inorder.begin() + ii,inorder.begin() + jj,mid);

        int dis = f - inorder.begin() - ii;

        TreeNode* root = new TreeNode(mid);
        root -> left = helper(preorder,i + 1,i + 1 + dis,inorder,ii,ii + dis);
        root -> right = helper(preorder,i + 1 + dis,j,inorder,ii + dis + 1,jj);
        return root;
    }
};

//迭代的方法，非常高效
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) return NULL;
        int ppre = 0, pin = 0;
        TreeNode *root = new TreeNode(preorder.at(ppre++));
        TreeNode *p = NULL;
        stack<TreeNode *> roots;
        roots.push(root);
        
        while (true) {
            if (inorder.at(pin) == roots.top()->val) {
                p = roots.top();
                roots.pop();
                pin++;
                if (pin == inorder.size()) break;
                if (roots.size() && inorder.at(pin) == roots.top()->val) continue;
                p->right = new TreeNode(preorder.at(ppre));
                ppre++;
                roots.push(p->right);
            }
            else {
                p = new TreeNode(preorder.at(ppre));
                ppre++;
                roots.top()->left = p;
                roots.push(p);
            }
        }
        
        return root;
    }
